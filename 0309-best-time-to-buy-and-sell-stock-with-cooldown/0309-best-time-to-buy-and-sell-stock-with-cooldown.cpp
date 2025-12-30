class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int>Dp(n + 2);
        for(int i = n - 1; i >= 0; i--){
            int profit = Dp[i + 1];
            for(int j = i + 1; j < n; j++){
                profit = max(profit,prices[j] - prices[i] + Dp[j + 2]);
            }
            Dp[i] = profit;
        }
        return Dp[0];
    }
};