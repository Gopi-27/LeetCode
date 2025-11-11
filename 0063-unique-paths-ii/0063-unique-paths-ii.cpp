class Solution {
public:
    int rec(int i,int j,vector<vector<int>>& obstacleGrid,vector<vector<int>>& Dp){
        if(i < 0 || j < 0)return 0;
        if(obstacleGrid[i][j])return 0;
        if(i == 0 && j == 0)return 1;

        if(Dp[i][j] != -1)return Dp[i][j];

        int ans = rec(i,j - 1,obstacleGrid,Dp);
        ans += rec(i - 1,j,obstacleGrid,Dp);
        return Dp[i][j] = ans;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        vector<vector<int>>Dp(n,vector<int>(m,-1));
        return rec(n - 1,obstacleGrid[0].size() - 1,obstacleGrid,Dp);
    }
};