def isValid(s):
        if s == '':
            return False
        for c in s:
            if c == '_':
                continue
            if c >= 'a' and c <= 'z':
                continue
            if c >= 'A' and c <= 'Z':
                continue
            if c >= '0' and c <= '9':
                continue
            return False
        return True
class Solution:
    def validateCoupons(self, code: List[str], businessLine: List[str], isActive: List[bool]) -> List[str]:
        ele = []
        gro = []
        pha = []
        res = []
        n = len(code)
        for i in range(n):
            if isActive[i]:
                flag = isValid(code[i])
                if(flag and businessLine[i] == 'electronics'):
                    ele.append(code[i])
                elif(flag and businessLine[i] == 'grocery'):
                    gro.append(code[i])
                elif(flag and businessLine[i] == 'pharmacy'):
                    pha.append(code[i])
                elif(flag and businessLine[i] == 'restaurant'):
                    res.append(code[i])
        ele.sort()
        gro.sort()
        pha.sort()
        res.sort()
        ele.extend(gro)
        ele.extend(pha)
        ele.extend(res)
        return ele
                