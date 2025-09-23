class Solution(object):
    def compareVersion(self, version1, version2):
        
        v1 = list(map(int,version1.split('.')))
        v2 = list(map(int,version2.split('.')))
        
        i = 0
        j = 0

        len1 = len(v1)
        len2 = len(v2)

        while (i < len1) and (j < len2):
            if v1[i] > v2[j] :
                return 1
            elif v1[i] < v2[j]:
                return -1
            else :
                i = i + 1
                j = j + 1
        
        while i < len1:
            if  v1[i] > 0 :
                return 1
            else :
                i = i + 1
        
        while j < len2 :
            if v2[j] > 0 :
                return -1
            else :
                j = j + 1
        
        return 0
        