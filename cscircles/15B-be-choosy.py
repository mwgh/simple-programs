# input integers n, k > 0
def choose(n, k):
   result = 1
   for i in range(k):
      j = i + 1      # j in [1, k]
      denominator = j
      numerator = n - k + j
      result *= numerator / denominator
   return int(result)
