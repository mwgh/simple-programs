#!/usr/bin/python
max = 1000000000

def sumDivisibleBy(n):
    p = (max - 1) / n
    return n * (p * (p + 1)) / 2

# a or b - (a and b)
print(sumDivisibleBy(3) + sumDivisibleBy(5) - sumDivisibleBy(15))
