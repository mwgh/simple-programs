width = int(input("Please enter the text width: "))

while True:
    lineIn = input("Please enter the text to center (END to stop): ")
    if lineIn == "END":
        break
    rightLength = (width - len(lineIn)) // 2
    leftLength = width - rightLength - len(lineIn)
    print(leftLength * '.' + lineIn + rightLength * '.')
