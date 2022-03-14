def hailstone(n):
   print(n)
   if n == 1:
      return
   elif n % 2 == 0:
      n //= 2
      return hailstone(n)
   else:
      n = 3 * n + 1
      return hailstone(n)
