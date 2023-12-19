def isPalindrome(S):
    lower = S.lower()
    return (lower == lower[::-1])
