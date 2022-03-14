def convertUnit(temp):
   unit = temp[len(temp) - 1]
   number = float(temp[0:len(temp) - 1])
   if unit == "F":
      output = (number - 32) * 5 / 9
      newUnit = "C"
   elif unit == "C":
      output = (number * 9 / 5) + 32
      newUnit = "F"
   return str(output) + newUnit

temp = input()
print(convertUnit(temp))
