class Solution {
public:
    int rec(int i,int j,int sum,int k,vector<vector<int>>& grid,vector<vector<vector<int>>> &Dp){
        if(j < 0)return 0;
        if(i < 0)return 0;
        if(i == 0 && j == 0){
            if((sum + grid[i][j]) % k == 0)return 1;
            return 0;
        }
        if(Dp[i][j][sum] != -1)return Dp[i][j][sum];

        int ans = (rec(i - 1,j,(sum + grid[i][j]) % k,k,grid,Dp)) % 1000000007;
        ans = (ans + rec(i,j - 1,(sum + grid[i][j]) % k,k,grid,Dp)) % 1000000007;
        return Dp[i][j][sum] = ans;
    }
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        // vector<vector<vector<int>>>Dp(n,vector<vector<int>>(m,vector<int>(k)));
        // // Tabulation
        // for(int s = 0; s < k; s++)if((s + grid[0][0]) % k == 0)Dp[0][0][s] = 1;
        // for(int i = 0; i < n; i++){
        //     for(int j = 0; j < m; j++){
        //         for(int s = 0; s < k; s++){
        //             if(i > 0)Dp[i][j][s] = (Dp[i][j][s] + Dp[i - 1][j][(s + grid[i][j]) % k]) % 1000000007;
        //             if(j > 0)Dp[i][j][s] = (Dp[i][j][s] + Dp[i][j - 1][(s + grid[i][j]) % k]) % 1000000007;
        //         }
        //     }
        // }
        // return Dp[n - 1][m - 1][0];

        // Space Optimization
        vector<vector<int>>prev(m,vector<int>(k));
        for(int s = 0; s < k; s++)if((s + grid[0][0]) % k == 0)prev[0][s] = 1;

        for(int j = 1; j < m; j++)
            for(int s = 0; s < k; s++)
                prev[j][s] += prev[j - 1][(s + grid[0][j]) % k];
            
        for(int i = 1; i < n; i++){
            vector<vector<int>>curr(m,vector<int>(k));
            for(int j = 0; j < m; j++){
                for(int s = 0; s < k; s++){
                    if(i > 0)curr[j][s] = (curr[j][s] + prev[j][(s + grid[i][j]) % k]) % 1000000007;
                    if(j > 0)curr[j][s] = (curr[j][s] + curr[j - 1][(s + grid[i][j]) % k]) % 1000000007;

                }
            }
            prev = curr;
        }
        return prev[m - 1][0];
    }
};