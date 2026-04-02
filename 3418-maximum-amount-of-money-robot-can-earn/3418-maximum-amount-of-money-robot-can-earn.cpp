class Solution {
public:
    int mini = -1e9;
    int maximumAmount(vector<vector<int>>& coins) {
        int n = coins.size();
        int m = coins[0].size();
        vector<vector<vector<int>>>Dp(n,vector<vector<int>>(m,vector<int>(3)));

        Dp[0][0][0] = coins[0][0];
        Dp[0][0][1] = max(0,coins[0][0]);
        Dp[0][0][2] = Dp[0][0][1];

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                for(int k = 0; k < 3; k++){
                    if(i == 0 && j == 0)continue;

                    if(coins[i][j] >= 0){
                        Dp[i][j][k] = coins[i][j] + max(((i > 0) ? Dp[i - 1][j][k] : mini),((j > 0) ? Dp[i][j - 1][k] : mini));
                    }else{// negative loose/neutral
                        Dp[i][j][k] = coins[i][j] + max(((i > 0) ? Dp[i - 1][j][k] : mini),((j > 0) ? Dp[i][j - 1][k] : mini));
                        if(k > 0){
                            Dp[i][j][k] = max({Dp[i][j][k],((i > 0) ? Dp[i - 1][j][k - 1] : mini),((j > 0) ? Dp[i][j - 1][k - 1] : mini)});
                        }
                    }
                }
            }
        }
        return Dp[n - 1][m - 1][2];
    }
};