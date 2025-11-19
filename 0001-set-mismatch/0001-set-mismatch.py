class Solution(object):
    def findErrorNums(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        nums.sort()
        n = len(nums)
        cur_sum = nums[0]
        extra = 0
        for i in range(1,n):
            if nums[i] != nums[i - 1]:
                cur_sum += nums[i]
            else :
                extra = nums[i]
        return [extra,(n * (n + 1))/2 - cur_sum]
        
