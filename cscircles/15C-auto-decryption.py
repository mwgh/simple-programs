# A = 65, Z = 90, text is upper case, fix > 26 shift
def encode(text, shift):
    charList = list(text)

    # x is element not index
    ordList = list(map(ord, charList))
    shiftedOrdList = list(map(lambda x: shiftNoSpace(x, shift), ordList))
    modOrdList = list(map(mod, shiftedOrdList))
    finalList = list(map(chr, modOrdList))
    finalString = "".join(finalList)
    return finalString

# adds shift to value except except space = 20
def shiftNoSpace(value, shift):
    if value == ord(" "):
        return value
    return value + shift

# mods values of non-uppercase characters into [65, 90], skipping space
def mod(value):
    if value == ord(" ") or value >= ord("A") and value <= ord("Z"):
        return value
    elif value < ord("A"):
        # subtract 1 for index 0
        diff = ord("A") - value - 1
        mod = ord("Z") - diff
    else: # value > ord("Z"):
        # subtract 1 for index 0
        diff = value - ord("Z") - 1
        mod = ord("A") + diff

    return mod

def decode(text, shift):
    return encode(text, -shift)

plainText = "JOIN ME AT EIGHT BY THE ZOO"
encodedText = "LQKP OG CV GKIJV DA VJG BQQ"

"""
print(decode(encodedText, 2) == plainText)
print(encode(plainText, 2) == encodedText)

print(encode("SPY CODER", 5))
print(decode("HUD", 6))

print(letterGoodness)
"""

# only works for upper case letter and space
def letterToGoodness(letter):
    letterGoodness = [0.0817, 0.0149, 0.0278, 0.0425, 0.127, 0.0223, 0.0202, 0.0609, 0.0697, 0.0015, 0.0077, 0.0402, 0.0241, 0.0675, 0.0751, 0.0193, 0.0009, 0.0599, 0.0633, 0.0906, 0.0276, 0.0098, 0.0236, 0.0015, 0.0197, 0.0007]
    if letter == " ":
        return 0
    num = ord(letter)
    index = num - ord("A")
    return letterGoodness[index]

def maxGoodString():
    encodedMessage = input()
    highestGoodness = 0
    word = ""

    for shift in range(26):
        goodness = 0

        decoded = decode(encodedMessage, shift)
        charList = list(decoded)
        for char in charList:
            goodness += letterToGoodness(char)
        if goodness > highestGoodness:
            highestGoodness = goodness
            word = decoded
    return word

print(maxGoodString())
