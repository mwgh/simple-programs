import math
L = float(input())
A = float(input())

for i in range(0,10):
   print( L * math.cos(A * math.cos(i * math.sqrt(9.8/L))) - L * math.cos(A) )
