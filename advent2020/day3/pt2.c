#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CHARACTERS_PER_LINE 31

/*
 * Loads each line of a file into an array and
 * returns the pointer to the array.
 */
char **loadItems(FILE *fp, int *arrayLengthPtr) {
  int i = 0;
  char item[CHARACTERS_PER_LINE + 1];
  char **items = malloc(sizeof(char *));

  while (fscanf(fp, "%s", item) == 1) {
    // Add one for the null terminator
    items[i] = malloc((CHARACTERS_PER_LINE + 1) * sizeof(char));
    strncpy(items[i], item, CHARACTERS_PER_LINE + 1);
    ++i;

    // reallocarray() frees the old memory block if necessary
    items = reallocarray(items, i + 1, sizeof(char *));
    if (items == NULL) {
      fprintf(stderr, "Error with reallocarray\n");
      exit(EXIT_FAILURE);
    }
  }

  // Remove the last allocated item, since i should be the number of items in
  // the array
  *arrayLengthPtr = i;

  items = reallocarray(items, *arrayLengthPtr, CHARACTERS_PER_LINE + 1);
  if (items == NULL) {
    fprintf(stderr, "Error with reallocarray's final call\n");
    exit(EXIT_FAILURE);
  }

  return items;
}

unsigned long countTrees(char **items, int *arrayLengthPtr, int movesRight,
                         int movesDown) {
  unsigned long trees = 0;
  char TREE = '#';
  char OPEN = '.';

  int x = 0;
  for (int y = 0; y < *arrayLengthPtr; y += movesDown) {
    x = (int)fmod(x, CHARACTERS_PER_LINE);

    if (items[y][x] == TREE) {
      ++trees;
    }
    x += movesRight;
  }
  return trees;
}

int main() {
  // Open the file
  FILE *fp;
  const char *mode = "r";
  const char *inFile = "input";

  fp = fopen(inFile, mode);
  if (fp == NULL) {
    fprintf(stderr, "Cannot open the input file named %s!\n", inFile);
    exit(EXIT_FAILURE);
  }

  // Find the array length and load the file contents
  int *arrayLengthPtr = malloc(sizeof(int));
  char **items = loadItems(fp, arrayLengthPtr);

  unsigned long t1 = countTrees(items, arrayLengthPtr, 1, 1);
  unsigned long t2 = countTrees(items, arrayLengthPtr, 3, 1);
  unsigned long t3 = countTrees(items, arrayLengthPtr, 5, 1);
  unsigned long t4 = countTrees(items, arrayLengthPtr, 7, 1);
  unsigned long t5 = countTrees(items, arrayLengthPtr, 1, 2);
  printf("%lu %lu %lu %lu %lu\n", t1, t2, t3, t4, t5);

  unsigned long int product = t1 * t2 * t3 * t4 * t5;
  printf("The product is %lu\n", product);

  for (int i = 0; i < *arrayLengthPtr; ++i) {
    free(items[i]);
  }
  free(items);
  free(arrayLengthPtr);

  fclose(fp);
  return EXIT_SUCCESS;
}
