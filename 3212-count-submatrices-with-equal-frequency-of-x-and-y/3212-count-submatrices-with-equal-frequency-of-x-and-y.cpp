class Solution {
public:
    int GetVal(int i,int j,int flag,vector<vector<char>>&grid,vector<vector<vector<int>>>& Dp){
        int cnt = (flag == 0) ? (grid[i][j] == 'X') ? 1 : 0 : (grid[i][j] == 'Y') ? 1 : 0;
        cnt += (i > 0) ? Dp[i - 1][j][flag] : 0;
        cnt += (j > 0) ? Dp[i][j - 1][flag] : 0;
        cnt -= (i > 0 && j > 0) ? Dp[i - 1][j - 1][flag]: 0;
        return cnt;
    }
    
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>>Dp(n,vector<vector<int>>(m,vector<int>(2)));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                Dp[i][j][0] = GetVal(i,j,0,grid,Dp);
                Dp[i][j][1] = GetVal(i,j,1,grid,Dp);
            }
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(Dp[i][j][0] > 0 && Dp[i][j][0] == Dp[i][j][1])ans++;
            }
        }
        return ans;
    }
};