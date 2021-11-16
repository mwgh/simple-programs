#include <stdio.h>
#include <stdlib.h>

/*
 * Loads the integers in a file into an array and
 * returns the pointer to the array.
 */
int *loadIntegers(FILE *fp, int *arrayLengthPtr) {
  int i = 0;
  int item = 0;
  int *integers = calloc(i + 1, sizeof(int));

  while (fscanf(fp, "%d", &item) == 1) {
    integers[i] = item;
    ++i;
    // reallocarray() frees the old memory block if necessary
    integers = reallocarray(integers, i + 1, sizeof(int));
    if (integers == NULL) {
      fprintf(stderr, "Error with reallocarray");
      exit(EXIT_FAILURE);
    }
  }

  // Remove the last allocated spot, since i should be the number of items in
  // the array
  *arrayLengthPtr = i;

  integers = reallocarray(integers, *arrayLengthPtr, sizeof(int));
  if (integers == NULL) {
    fprintf(stderr, "Error with reallocarray's final call");
    exit(EXIT_FAILURE);
  }

  return integers;
}

int findProductForSum(int *integers, int *arrayLengthPtr) {
  int SUM = 2020;

  for (int i = 0; i < *arrayLengthPtr; ++i) {
    int first = integers[i];
    for (int j = i + 1; j < *arrayLengthPtr; ++j) {
      int second = integers[j];

      for (int k = j + 1; k < *arrayLengthPtr; ++k) {
        int third = integers[k];

        if (first + second + third == SUM) {
          printf("1st = %d\t2nd = %d\t3rd = %d\n", first, second, third);
          return first * second * third;
        }
      }
    }
  }
  return 0;
}

int main() {
  // Open the file
  FILE *fp;
  const char *mode = "r";
  const char *inFile = "input";

  fp = fopen(inFile, mode);
  if (fp == NULL) {
    fprintf(stderr, "Can't open input file %s!\n", inFile);
    exit(EXIT_FAILURE);
  }

  // Find the array length and load the file contents
  int *arrayLengthPtr = malloc(sizeof(int));
  int *integers = loadIntegers(fp, arrayLengthPtr);

  int product = findProductForSum(integers, arrayLengthPtr);
  printf("The product is %d\n", product);

  free(arrayLengthPtr);
  free(integers);

  fclose(fp);
  return EXIT_SUCCESS;
}
