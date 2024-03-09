#!/usr/bin/python
import math

# num = 13195
num = 600851475143
# num = 100000

for i in range(2, int(math.sqrt(num))):
	if num % i == 0:
		print(i)
		num /= i
