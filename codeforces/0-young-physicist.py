#! /usr/bin/python
n = int(input())

sum_x = 0
sum_y = 0
sum_z = 0

for i in range(n):
	line = input()
	x, y, z = map(int, line.split())

	sum_x += x
	sum_y += y
	sum_z += z

if sum_x == 0 and sum_y == 0 and sum_z == 0:
	print("YES")
else:
	print("NO")
