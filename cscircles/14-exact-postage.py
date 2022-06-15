def postalValidate(S):
   newS = S.replace(" ", "")
   if len(newS) != 6: return False
   for i in range(len(newS), 2):
      if newS[i:i+1].isalpha(): continue
      else: return False
      return True
   for i in range(1, len(newS), 2):
      if newS[i:i+1].isdigit(): continue
      else: return False
   return newS.upper()
