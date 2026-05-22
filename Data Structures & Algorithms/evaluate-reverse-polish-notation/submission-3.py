class Solution:

    def evalRPN(self, tokens: List[str]) -> int:
        s = []
        for i in tokens:
            if (i == "+" or i =="-" or i == "*" or i =="/"):
                n2 = s.pop()
                n1 = s.pop()
                if i == "+":
                    s.append(n1+n2)
                elif i == "-":
                    s.append(n1-n2)
                elif i == "*":
                    s.append(n1*n2)
                else:
                    if(n1/n2 != n1//n2 and n1/n2 < 0):
                        s.append(n1//n2 + 1)
                    else:
                        s.append(n1//n2)
            else:
                s.append(int(i))

        return s[0]