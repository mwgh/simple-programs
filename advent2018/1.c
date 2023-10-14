#include <stdio.h>
#include <stdlib.h>

/*
 * Sums the integers in a file
 */
int sumFile(FILE *fp) {
    int freqChange;
    int currentFreq = 0;

    // 1 int on line
    while (fscanf(fp, "%d", &freqChange) == 1) {
        currentFreq += freqChange;
        printf("Current freq is %d, freq change is %d\n", currentFreq, freqChange);
    }
    return currentFreq;
}

int main() {
    FILE *fp;
    char *inFile = "input";

    fp = fopen(inFile, "r");
    if (fp == NULL) {
        fprintf(stderr, "Can't open input file %s!\n", inFile);
        exit(1);
    }

    printf("Resulting frequency is %d\n", sumFile(fp));

    fclose(fp);
}
