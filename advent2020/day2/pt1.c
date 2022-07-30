#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_PASSWORD_LENGTH 20

struct PasswordInfo {
  int lowestFrequency;
  int highestFrequency;
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

  while (fscanf(fp, "%d-%d %c: %s", &pass.lowestFrequency,
                &pass.highestFrequency, &pass.letter, pass.password) == 4) {
    items[i] = pass;
    ++i;
    // reallocarray() frees the old memory block if necessary
    items = reallocarray(items, i + 1, ARRAY_ITEM_SIZE);
    if (items == NULL) {
      fprintf(stderr, "Error with reallocarray");
      exit(1);
    }
  }

  // Remove the last allocated item, since i should be the number of items in
  // the array
  *arrayLengthPtr = i;

  items = reallocarray(items, *arrayLengthPtr, ARRAY_ITEM_SIZE);
  if (items == NULL) {
    fprintf(stderr, "Error with reallocarray's final call");
    exit(1);
  }

  return items;
}

void printStruct(struct PasswordInfo pass) {
  printf("%d, %d, %c, %s\n", pass.lowestFrequency, pass.highestFrequency,
         pass.letter, pass.password);
}

void printStructs(struct PasswordInfo *items, int *arrayLengthPtr) {
  for (int i = 0; i < *arrayLengthPtr; ++i) {
    struct PasswordInfo item = items[i];
    printStruct(item);
  }
}

bool isValid(struct PasswordInfo pass) {
  int occurrences = 0;
  for (int i = 0; i < strlen(pass.password); ++i) {
    if (pass.password[i] == pass.letter)
      ++occurrences;
  }

  return (occurrences >= pass.lowestFrequency &&
      occurrences <= pass.highestFrequency);
}

int countValid(struct PasswordInfo *items, int *arrayLengthPtr) {
  int valid = 0;
  for (int i = 0; i < *arrayLengthPtr; ++i) {
    if (isValid(items[i]))
      ++valid;
  }
  return valid;
}

int main() {
  // Open the file
  const char *inFile = "input";
  FILE *fp = fopen(inFile, "r");
  if (fp == NULL) {
    fprintf(stderr, "Can't open input file %s!\n", inFile);
    exit(1);
  }

  // Find the array length and load the file contents
  int *arrayLengthPtr = malloc(sizeof(int));
  struct PasswordInfo *items = loadItems(fp, arrayLengthPtr);
  printf("The array length is %d\n", *arrayLengthPtr);
  printf("There are %d valid passwords\n", countValid(items, arrayLengthPtr));

  free(arrayLengthPtr);
  free(items);

  fclose(fp);
  return 0;
}
