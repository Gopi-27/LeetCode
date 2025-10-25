class Solution:
    def totalMoney(self, n: int) -> int:
        val = [1,2,3,4,5,6,7]
        ans = 0
        i = 0
        for _ in range(n):
            ans += val[i]
            val[i] += 1
            i = (i + 1) % 7
        return ans

