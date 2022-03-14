def lowerChar(char):
   if 65 <= ord(char) <= 90:
      return chr(ord(char) + 32)
   else:
      return char

def lowerString(string):
   result = ""
   for i in range(0,len(string)):
      result = result + lowerChar(string[i])
   return result
