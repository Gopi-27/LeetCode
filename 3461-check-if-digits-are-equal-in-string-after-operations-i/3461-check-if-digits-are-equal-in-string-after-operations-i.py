class Solution:
    def hasSameDigits(self, s: str) -> bool:
        n = len(s)
        for _ in range(n - 2):
            temp = ""
            m = len(s)
            for i in range(1,m):
                res = (int(s[i - 1]) + int(s[i])) % 10
                temp = temp + str(res)
            s = temp
        return s[0] == s[1]


            


        