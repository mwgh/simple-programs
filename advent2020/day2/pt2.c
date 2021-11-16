#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORD_LENGTH 20

// The positions are 1-indexed
struct PasswordInfo {
  int firstPosition;
  int secondPosition;
  char letter;
  char password[MAX_PASSWORD_LENGTH];
};

/*
 * Loads the structs in a file into an array and
 * returns the pointer to the array.
 */
struct PasswordInfo *loadItems(FILE *fp, int *arrayLengthPtr) {
  const int ARRAY_ITEM_SIZE = sizeof(struct PasswordInfo);

  int i = 0;
  struct PasswordInfo pass;
  struct PasswordInfo *items = calloc(i + 1, ARRAY_ITEM_SIZE);

  while (fscanf(fp, "%d-%d %c: %s", &pass.firstPosition, &pass.secondPosition,
                &pass.letter, pass.password) == 4) {
    items[i] = pass;
    ++i;
    // reallocarray() frees the old memory block if necessary
    items = reallocarray(items, i + 1, ARRAY_ITEM_SIZE);
    if (items == NULL) {
      fprintf(stderr, "Error with reallocarray");
      exit(EXIT_FAILURE);
    }
  }

  // Remove the last allocated item, since i should be the number of items in
  // the array
  *arrayLengthPtr = i;

  items = reallocarray(items, *arrayLengthPtr, ARRAY_ITEM_SIZE);
  if (items == NULL) {
    fprintf(stderr, "Error with reallocarray's final call");
    exit(EXIT_FAILURE);
  }

  return items;
}

void printStruct(struct PasswordInfo pass) {
  printf("%d, %d, %c, %s\n", pass.firstPosition, pass.secondPosition,
         pass.letter, pass.password);
}

void printStructs(struct PasswordInfo *items, int *arrayLengthPtr) {
  for (int i = 0; i < *arrayLengthPtr; ++i) {
    struct PasswordInfo item = items[i];
    printStruct(item);
  }
}

bool isValid(struct PasswordInfo pass) {
  char firstChar = pass.password[pass.firstPosition - 1];
  char secondChar = pass.password[pass.secondPosition - 1];

  bool onlyFirstCharMatches =
      (firstChar == pass.letter) && (secondChar != pass.letter);
  bool onlySecondCharMatches =
      (firstChar != pass.letter) && (secondChar == pass.letter);
  if (onlyFirstCharMatches || onlySecondCharMatches) {
    return true;
  }

  return false;
}

int countValid(struct PasswordInfo *items, int *arrayLengthPtr) {
  int valid = 0;
  for (int i = 0; i < *arrayLengthPtr; ++i) {
    if (isValid(items[i])) {
      ++valid;
    }
  }
  return valid;
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
  struct PasswordInfo *items = loadItems(fp, arrayLengthPtr);
  printf("The array length is %d\n", *arrayLengthPtr);

  int valid = countValid(items, arrayLengthPtr);
  printf("There are %d valid passwords\n", valid);

  free(arrayLengthPtr);
  free(items);

  fclose(fp);
  return EXIT_SUCCESS;
}
