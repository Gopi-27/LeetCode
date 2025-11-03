class Solution(object):
    def minCost(self, colors, neededTime):
        ans, n,i = 0,len(colors),0
        while i < n:
            totSum = neededTime[i]
            maxi = neededTime[i]
            i += 1
            while i < n and colors[i - 1] == colors[i]:
                totSum += neededTime[i]
                maxi = max(maxi,neededTime[i])
                i += 1
            totSum -= maxi
            ans += totSum
        return ans



        """
        :type colors: str
        :type neededTime: List[int]
        :rtype: int
        """
        