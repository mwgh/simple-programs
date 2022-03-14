startTime = input()
D = int(input())

for i in range(0, len(startTime)-1):
   if startTime[i] == ':':
      h = int(startTime[:i]) #23
      m = int(startTime[i+1:])
      hours = h + (m + D) // 60
      if hours >= 24:
         hours = "0" + str(hours % 24)
      #print(hours)
      minutes = (m + D) % 60
      if minutes < 10:
         minutes = "0" + str(minutes)
      print(str(hours) + ':' + str(minutes))
