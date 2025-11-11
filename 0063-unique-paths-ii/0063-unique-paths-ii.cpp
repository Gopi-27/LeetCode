class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        vector<vector<int>>Dp(n,vector<int>(m));
        // tabulation
        Dp[0][0] = 1;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(obstacleGrid[i][j])Dp[i][j] = 0;
                else{
                    if(i > 0)Dp[i][j] = Dp[i - 1][j];
                    if(j > 0)Dp[i][j] += Dp[i][j - 1];
                }
            }
        }
        return Dp[n - 1][m - 1];
    }
};