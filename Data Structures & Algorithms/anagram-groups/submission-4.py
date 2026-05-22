class Solution:
    def code(self, s1: str):
        d = {}
        for i in s1:
            if i in d.keys():
                d[i] += 1
            else:
                d[i] = 1
        ans = ""

        for i in sorted(d.keys()):
            ans += i
            ans += str(d[i])
        return ans

    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        print(self.code("apple"))
        d = {}

        for i in strs:
            if self.code(i) in d:
                d[self.code(i)].append(i)
            else:
                d[self.code(i)] = [i]
        ans = []
        for i in d.keys():
            ans.append(d[i])
            
        return ans
        