n = 0
try:
	n = int(input("Enter the max number: "))
except ValueError:
	exit("Not a number")

sum_of_squares = 0

for i in range(1, n+1):
	sum_of_squares += i * i

total = (1 + n) * (n/2)#11*5=55, 10*4.5=45
print(int((total * total) - sum_of_squares))
