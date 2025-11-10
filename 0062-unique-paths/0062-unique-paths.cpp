class Solution {
public:
    int uniquePaths(int n, int m) {
        vector<vector<int>>Dp(n,vector<int>(m));
        // tabulation
        Dp[0][0] = 1;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
               if(j > 0)Dp[i][j] = Dp[i][j - 1];
               if(i > 0)Dp[i][j] += Dp[i - 1][j];
            }
        }
        return Dp[n - 1][m - 1];
    }
};