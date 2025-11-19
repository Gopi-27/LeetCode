class Solution(object):
    def smallerNumbersThanCurrent(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        ans = []
        for ele in nums:
            ans.append(sum(1 for b in nums if b < ele)) 
        return ans
        