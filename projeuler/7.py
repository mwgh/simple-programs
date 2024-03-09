import math

def sieve(MAX):
    """Return is_prime[MAX] for numbers [0, MAX - 1] with sieve of eratosthenes
    True if N is prime, False if N is composite
    Mark multiples of each prime as composite (not primes themselves)
    multiple = p*p, p*p + p, p*p + 2p, ... are composite
    """
    is_prime = [False, False]

    for i in range(2, MAX):
        is_prime.append(True)

    for p in range(2, int(math.sqrt(MAX))):
        if is_prime[p] == True:
            for multiple in range(p * p, MAX, p):
                is_prime[multiple] = False
    return is_prime

is_prime = sieve(1000001)

assert(is_prime[2])
assert(is_prime[5])
assert(is_prime[7])
assert(is_prime[11])
assert(is_prime[13])
assert(not is_prime[12])

primes = []
i = 2
for x in is_prime[2:]:
	if x:
		primes.append(i)
	i += 1

num = 10001
print(f"{num} prime is {primes[num-1]}")
