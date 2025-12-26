class Solution {
public:
    int maxScore(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>Dp(m,vector<int>(n));
        for(int i = m - 1; i >= 0; i--){
            for(int j = n - 1; j >= 0; j--){
                if(i == m - 1 && j == n - 1)continue;

                int maxi = INT_MIN;
                
                for(int r = j + 1; r < n; r++)
                    maxi = max(maxi,(grid[i][r] - grid[i][j]) + max(0,Dp[i][r]));
                for(int d = i + 1; d < m; d++){
                    maxi = max(maxi,(grid[d][j] - grid[i][j]) + max(0,Dp[d][j]));
                }

                Dp[i][j] = maxi;
            }
        }
        int maxi = INT_MIN;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i == m - 1 && j == n - 1)continue;
                maxi = max(maxi,Dp[i][j]);
            }
        }
        return maxi;
    }
};