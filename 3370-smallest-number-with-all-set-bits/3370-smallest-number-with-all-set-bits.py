class Solution(object):
    def smallestNumber(self, n):
        k = int(math.log(n,2)) + 1
        return (1 << k) - 1
        """
        :type n: int
        :rtype: int
        """
        