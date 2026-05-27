class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        n = 0

        for i in range(len(digits)):
            n*=10
            n+=digits[i]
        return list(str(n+1))