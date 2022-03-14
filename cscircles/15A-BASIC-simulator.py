# def getBASIC from subtask 1
def getBASIC():
   list = []
   while True:
      lineIn = input()
      list.append(lineIn)
      if lineIn.endswith("END"):
         break
   return list

# def findLine from subtask 2
def findLine(prog, target):
   for i in range(len(prog)):
      if prog[i].startswith(target):
         return i

# def execute from subtask 3
def execute(prog):
   location = 0
   visited = [False] * len(prog)
   while True:
      line = prog[location]
      if line.endswith("END"):
         return "success"
      
      splitLine = line.split()
      T = splitLine[-1]
      
      location = findLine(prog, T)
      if visited[location]:
         return "infinite loop"
      else:
         visited[location] = True

print(execute(getBASIC()))
