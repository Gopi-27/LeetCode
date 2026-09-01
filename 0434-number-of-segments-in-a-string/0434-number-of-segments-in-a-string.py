class Solution(object):
    def countSegments(self, s):
        words = s.split()
        cnt = 0
        for w in words:
            if len(w) >= 1:
                cnt += 1
        return cnt
        