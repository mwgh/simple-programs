def replace(list, X, Y):
    while X in list:
        list.insert(list.index(X), Y)
        list.remove(X)
