import math

def choose(n, k):
	result = 1
	for i in range(k):
		j = i + 1
		denominator = j
		numerator = n - k + j
		result *= numerator / denominator
		print(result)
	return math.ceil(result)

N = 20
print('Number of lattice paths in NxN where N =', N, 'grid is', choose(2*N, N))
