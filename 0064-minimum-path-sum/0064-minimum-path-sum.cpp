class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>Dp(n,vector<int>(m,-1));
        // Tabulation
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(i == 0 && j == 0)Dp[i][j] = grid[i][j];
                else{
                    int mini = INT_MAX;
                    if(i > 0)mini = min(mini,Dp[i - 1][j]);
                    if(j > 0)mini = min(mini,Dp[i][j - 1]);
                    Dp[i][j] = mini + grid[i][j];
                }
            }
        }
        return Dp[n - 1][m - 1];
    }
};