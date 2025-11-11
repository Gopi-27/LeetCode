class Solution {
public:
    int rec(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& Dp){
        if(i < 0 || j < 0)return INT_MAX;
        if(i == 0 && j == 0)return grid[i][j];
        if(Dp[i][j] != -1)return Dp[i][j];
        int ans = rec(i,j - 1,grid,Dp);
        ans = min(ans,rec(i - 1,j,grid,Dp));

        return Dp[i][j] = grid[i][j] + ans;
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>Dp(n,vector<int>(m,-1));
        return rec(n - 1, m - 1,grid,Dp);
    }
};