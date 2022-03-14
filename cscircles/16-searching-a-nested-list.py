def nestedListContains(NL, target):
    if isinstance(NL, int):
        return NL == target

    contains = False
    for i in range(0, len(NL)):
        contains = contains or nestedListContains(NL[i], target)
    return contains
