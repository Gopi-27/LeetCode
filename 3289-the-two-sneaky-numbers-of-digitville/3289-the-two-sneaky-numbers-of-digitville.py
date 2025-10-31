import numpy as np
class Solution(object):
    def getSneakyNumbers(self, nums):
        ans = []
        frr = np.zeros(len(nums))
        for ele in nums:
            if frr[ele]:
                ans.append(ele)
            else:
                frr[ele] += 1
        return ans 

        