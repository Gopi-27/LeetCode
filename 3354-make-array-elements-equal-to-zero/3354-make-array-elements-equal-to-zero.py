class Solution(object):
    def countValidSelections(self, nums):
        pre_sum = 0
        tot_sum = sum(nums)
        ans = 0
        for ele in nums:
            pre_sum += ele
            rem = tot_sum - pre_sum
            dif = abs(rem - pre_sum)
            if ele == 0 and dif <= 1:
                ans += 2 - dif
        return ans

        