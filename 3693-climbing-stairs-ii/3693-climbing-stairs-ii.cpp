class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        vector<int>Dp(n + 3);
        Dp[n + 1] = 1e8;
        Dp[n + 2] = 1e8;
        costs.push_back(1e5);
        costs.push_back(1e5);
        for(int i = n - 1; i >= 0; i--){
            // take min of one,two,three steps
            Dp[i] = min(costs[i] + 1 + Dp[i + 1],min(costs[i + 1] + 4 + Dp[i + 2] ,costs[i + 2] + 9 + Dp[i + 3]));
        }
        return Dp[0];
    }
};