class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>Dp(m,vector<int>(n));
        for(int j = n - 1; j >= 0; j--){
            for(int i = 0; i < m; i++){
                int up = 0;
                int right = 0;
                int down = 0;
                int cnt = 0;
                if(i - 1 >= 0 && j + 1 < n && grid[i][j] < grid[i - 1][j + 1]){
                    up = Dp[i - 1][j + 1];
                    cnt++;
                }
                if(j + 1 < n && grid[i][j] < grid[i][j + 1]){
                    right = Dp[i][j + 1];
                    cnt++;
                }

                if(i + 1 < m && j + 1 < n && grid[i][j] < grid[i + 1][j + 1]){
                    down = Dp[i + 1][j + 1];
                    cnt++;
                }
                int ans = max({up,right,down});
                Dp[i][j] = (cnt > 0)? ans + 1:0;
            }
        }
        int maxi = 0;
        for(int i = 0; i < m; i++){
            maxi = max(maxi,Dp[i][0]);
        }
        return maxi;
    }
};