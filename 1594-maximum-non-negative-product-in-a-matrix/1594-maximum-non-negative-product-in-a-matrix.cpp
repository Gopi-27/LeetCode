class Solution {
public:
    int mod = 1e9 + 7;
    int maxProductPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<vector<long long>>>Dp(m,vector<vector<long long>>(n,vector<long long>(2)));
        for(int i = m - 1; i >= 0; i--){
            for(int j = n - 1; j >= 0; j--){
                if(j == n - 1 && i == m - 1){
                    Dp[i][j][0] = grid[i][j];
                    Dp[i][j][1] = grid[i][j];
                    continue;
                }
                // four choices
                int val = grid[i][j];
                long long mini;
                long long maxi;
                if(j + 1 < n && i + 1 < m){
                    mini = min(val * Dp[i][j + 1][0],val * Dp[i][j + 1][1]);
                    mini = min(mini,val * Dp[i + 1][j][0]);
                    mini = min(mini,val * Dp[i + 1][j][1]);

                    maxi = max(val * Dp[i][j + 1][0],val * Dp[i][j + 1][1]);
                    maxi = max(maxi,val * Dp[i + 1][j][0]);
                    maxi = max(maxi,val * Dp[i + 1][j][1]);
                }else{
                    if(j + 1 < n){
                        mini = min(val * Dp[i][j + 1][0],val * Dp[i][j + 1][1]);
                        maxi = max(val * Dp[i][j + 1][0],val * Dp[i][j + 1][1]);
                      
                    }else{
                        mini = min(val * Dp[i + 1][j][0],val * Dp[i + 1][j][1]);
                        maxi = max(val * Dp[i + 1][j][0],val * Dp[i + 1][j][1]);
                    }
                }
                Dp[i][j][0] = mini;  
                Dp[i][j][1] = maxi;
            }
        }
        long long ans = max(Dp[0][0][0],Dp[0][0][1]);
        return (ans >= 0)? (ans % mod): -1;
    }
};