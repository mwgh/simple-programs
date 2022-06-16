def check(S):
    if len(S) != 19:
        return False
    gaps = [4, 9, 14]
    total = 0

    for i in range(len(S)):
        if i in gaps and not S[i].isspace():
            return False
        elif i not in gaps and not S[i].isspace():
            if not S[i].isdigit():
                return False
            else:
                # not space and is digit
                digit = int(S[i])
                total += digit
    if total % 10 == 0:
        return True
    return False
