def digitalRoot(n):
   if n < 10:
      return n
   sum = digitalSum(n)
   return digitalRoot(sum)
# digitalRoot(2019) = digitalRoot(digitalSum(2019)) = digitalRoot(12) = digitalRoot(3)
