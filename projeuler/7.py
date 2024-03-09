n = 2
prime_count = 0
primes = []

def is_prime(x):
	prime = True
	for i in range(x-1, 1, -1):
		if x % i == 0:
			prime = False
			break
	return prime

assert(is_prime(2))
assert(is_prime(5))
assert(is_prime(7))
assert(is_prime(11))
assert(is_prime(13))
assert(not is_prime(12))

while prime_count <= 10001:
	if is_prime(n):
		primes.append(n)
		prime_count += 1
	n += 1

print(f"prime_count={prime_count}, len(primes)={len(primes)}, primes={primes}")
print(primes[10000])
