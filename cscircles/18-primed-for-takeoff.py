import math

def sieve(MAX):
    """Return a list of length MAX for numbers [0, MAX - 1] with sieve of eratosthenes
    True if N is prime, False if N is composite
    Mark multiples of each prime as composite (not primes themselves)
    multiple = p*p, p*p + p, p*p + 2p, ... are composite
    """
    isPrime = [False, False]

    for i in range(2, MAX):
        isPrime.append(True)

    for p in range(2, int(math.sqrt(MAX))):
        if isPrime[p]:
            for multiple in range(p * p, MAX, p):
                isPrime[multiple] = False
    return isPrime

MAX = 1000001
isPrime = sieve(MAX)
