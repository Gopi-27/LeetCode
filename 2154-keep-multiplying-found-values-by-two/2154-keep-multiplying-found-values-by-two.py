class Solution(object):
    def findFinalValue(self, nums, original):
        """
        :type nums: List[int]
        :type original: int
        :rtype: int
        """
        nums.sort()
        for ele in nums:
            if ele == original:
                original *= 2
        return original