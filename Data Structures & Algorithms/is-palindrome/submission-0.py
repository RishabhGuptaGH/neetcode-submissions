class Solution:
    def isPalindrome(self, s: str) -> bool:
        a = ""
        for i in s:
            i = ord(i)
            if((i>=48 and i<=57)or(i>=65 and i<=90)or(i>=97 and i<=122)):
                a+=chr(i)
        a = a.lower()
        return a==a[::-1]