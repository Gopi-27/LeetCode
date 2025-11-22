class Solution(object):
    def minimumOperations(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        return sum(min(b % 3, 3 - (b % 3)) for b in nums)