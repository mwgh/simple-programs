import math

def sieve(max_len):
    """Return a list of length max_len for numbers [0, max_len - 1] with sieve of eratosthenes
    True if N is prime, False if N is composite
    Mark multiples of each prime as composite (not primes themselves)
    multiple = p*p, p*p + p, p*p + 2p, ... are composite
    """
    is_prime = [False, False]

    for i in range(2, max_len):
        is_prime.append(True)

    for p in range(2, int(math.sqrt(max_len))):
        if is_prime[p]:
            for multiple in range(p * p, max_len, p):
                is_prime[multiple] = False
    return is_prime

is_prime = sieve(1000001)

assert(is_prime[2])
assert(is_prime[5])
assert(is_prime[7])
assert(is_prime[11])
assert(is_prime[13])
assert(not is_prime[12])

primes = [i for i in range(len(is_prime)) if is_prime[i]]

num = 10001
print(f"{num} prime is {primes[num-1]}")
