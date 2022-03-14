width = int(input())

# delete this comment and enter your code here
while True:
   lineIn = input()
   if lineIn == "END":
      break
   rightLength = (width - len(lineIn)) // 2
   leftLength = width - rightLength - len(lineIn)
   print(leftLength * '.' + lineIn + rightLength * '.')
