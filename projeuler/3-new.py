#!/usr/bin/python
import math

# num = 13195
num = 600851475143
lastFactor = 1
end = int(math.sqrt(num))
step = 2
# num = 100000

if num % 2 == 0:
	lastFactor = 2

for i in range(3, end, step):
	if num % i == 0:
		lastFactor = i
		num /= i

print(lastFactor)
