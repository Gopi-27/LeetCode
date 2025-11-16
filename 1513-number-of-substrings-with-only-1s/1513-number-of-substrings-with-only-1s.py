class Solution(object):
    def numSub(self, s):
        """
        :type s: str
        :rtype: int
        """
        ans = 0
        l = s.split('0')
        for b in l:
            n = len(b)
            ans = (ans + ((n * (n + 1)/2) % 1000000007)) % 1000000007
        return ans
        