needle = input()
haystack = input()
total = 0
for i in range(0, len(haystack)):
   if haystack[i:len(needle)+i] == needle:
      total +=1
print(str(total))
