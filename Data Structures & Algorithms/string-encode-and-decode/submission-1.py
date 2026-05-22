class Solution:
    def Double1(self, s: str):
        ans = ""
        for i in s:
            ans += str(i)*2
        return ans

    def encode(self, strs: List[str]) -> str:
        ans = ""
        for i in strs:
            ans += str(self.Double1(i))
            ans += "@/"
        return ans

    def decode(self, s: str) -> List[str]:
        l = []
        word = ""

        i = 0
        while(i < len(s)-1):
            if(s[i] == s[i+1]):
                word += s[i]
            else:
                l.append(word)
                word = ""
            i+= 2
        if (word != ""):
            l.append(word)
        return l
