import math

def is_prime(n):
	if n == 1: return False
	elif n < 4: return True
	elif n % 2 == 0: return False
	elif n < 9: return True
	elif n % 3 == 0: return False
	else:
		r = math.floor(math.sqrt(n))
		f = 5
		while f <= r:
			if n % f == 0:
				return False
			if n % (f+2) == 0:
				return False
			f += 6
	return True

limit = 10001
count = 1
candidate = 1
while count < limit:
	candidate += 2
	if is_prime(candidate):
		count += 1

print('Prime number', limit, 'is', candidate)
