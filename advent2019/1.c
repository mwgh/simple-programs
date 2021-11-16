#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// 14 / 3 - 2 = 4 - 2 = 2. -2 <= 0
int calculateFuel(int mass) {
    const int fuel = mass / 3 - 2;
    if (fuel <= 0) {
        return 0;
    }
    return fuel + calculateFuel(fuel);
}

void testCalculateFuel() {
    assert(calculateFuel(14) == 2);
    assert(calculateFuel(1969) == 966);
    assert(calculateFuel(100756) == 50346);
}

/*
 * Sums the integers in a file
 */
int sumFile(FILE *fp) {
    int item;
    int total = 0;

    // 1 int on line
    while (fscanf(fp, "%d", &item) == 1) {
        const int fuel = calculateFuel(item);
        total += fuel;
        printf("The total is %d and the item is %d\n", total, fuel);
    }
    return total;
}

int main() {
    testCalculateFuel();

    FILE *fp;
    const char *mode = "r";
    const char *inFile = "input";

    fp = fopen(inFile, mode);
    if (fp == NULL) {
        fprintf(stderr, "Can't open input file %s!\n", inFile);
        exit(1);
    }

    const int fuelNeeded = sumFile(fp);
    printf("The fuel needed is %d\n", fuelNeeded);

    fclose(fp);
}
