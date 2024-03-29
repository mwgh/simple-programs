def digitalSum(n):
    if n < 10:
        return n
    sum = 0
    remainder = n % 10
    sum += remainder
    rest = n // 10
    sum += digitalSum(rest)
    return sum

def digitalRoot(n):
    if n < 10:
        return n
    sum = digitalSum(n)
    return digitalRoot(sum)
