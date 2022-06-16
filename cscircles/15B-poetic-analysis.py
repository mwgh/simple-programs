# input is standard input
# returns dictionary (hash table) of word frequencies
def wordsHash():
    words = {}
    while True:
        line = input()
        if line == "###":
            return words
        splitLine = line.lower().split()

        # add all words in line to hash table
        for word in splitLine:
            if not word in words: # search O(1)
                words[word] = 0 # insert O(1)
            words[word] += 1 # search O(1)

# returns the key of the largest value (most frequently seen word)
def mostFrequentWord():
    maxTimesSeen = 0
    words = wordsHash()
    for word in iter(words.keys()):
        if words[word] > maxTimesSeen:
            maxTimesSeen = words[word]
            targetWord = word   
    return targetWord

print(mostFrequentWord())
