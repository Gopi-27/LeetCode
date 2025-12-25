class Solution {
public:
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>Dp(m,vector<int>(n));
        for(int j = 0; j < n; j++)Dp[m - 1][j] = grid[m - 1][j];

        for(int i = m - 2; i >= 0; i--){
            for(int j = 0; j < n; j++){
                int mini = INT_MAX;
                int val = grid[i][j];
                for(int col = 0; col < n; col++){
                    mini = min(mini, val + moveCost[val][col] + Dp[i + 1][col]);
                }
                Dp[i][j] = mini;
            }
        }
        int mini = INT_MAX;
        for(int j = 0; j < n; j++)mini = min(mini,Dp[0][j]);
        return mini;
    }
};