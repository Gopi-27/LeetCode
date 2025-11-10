class Solution {
public:
    int rec(int i,int j,vector<vector<int>>& Dp){
        if(i < 0 || j  < 0)return 0;
        if(i == 0 && j == 0)return 1;
        if(Dp[i][j] != -1)return Dp[i][j];
        int ans = rec(i - 1,j,Dp);
        ans += rec(i,j - 1,Dp);
        return Dp[i][j] = ans;
    }
    int uniquePaths(int n, int m) {
        vector<vector<int>>Dp(n,vector<int>(m,-1));
        return rec(n - 1,m - 1,Dp);
    }
};