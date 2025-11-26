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
        vector<vector<vector<int>>>Dp(n,vector<vector<int>>(m,vector<int>(k,-1)));
        return rec(n - 1,m - 1,0,k,grid,Dp);
    }
};