class Solution(object):
    def kLengthApart(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: bool
        """
        n = len(nums)
        prev_idx = -n
        for i in range(n):
            if nums[i]:
                if i - prev_idx <= k:
                    return False
                prev_idx = i
        return True
        