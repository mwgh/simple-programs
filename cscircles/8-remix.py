S = input()
for i in range(0, len(S)):
    if S[i] == "+":
        print(int(S[:i]) + int(S[i+1:]))
