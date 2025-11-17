class Solution {
public:
    int rec(int level,int amount,vector<int>& coins,vector<vector<int>>& Dp){
        if(amount == 0)return 0; 
        if(level < 0)return -1;

        if(Dp[level][amount] != -2)return Dp[level][amount];
        int ans = INT_MAX;
        int quo = amount/coins[level];
        bool flag = 1;
        for(int q = 0; q <= quo; q++){
            int val = rec(level - 1,amount - (q * coins[level]),coins,Dp);
            if(val != -1){
                ans = min(ans,val + q);
                flag = 0;
            }
        }
        if(flag)ans = -1;
        return Dp[level][amount] = ans;
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>>Dp(n,vector<int>(amount + 1,-2));
        return rec(n - 1,amount,coins,Dp);
    }
};