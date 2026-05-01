class Solution {
public:
    int rec(int i, int j, int k,vector<vector<int>>& grid,vector<vector<vector<int>>>&Dp){
        
        if(i >= grid.size() || j >= grid[0].size())return -1;
        if(grid[i][j] && !k)return -1;
        if(i == grid.size() - 1 && j == grid[0].size() - 1)return grid[i][j];
        
        if(Dp[i][j][k] != -10)return Dp[i][j][k];
        
        int right = rec(i,j + 1, (grid[i][j] == 0)? k : k - 1,grid,Dp);
        if(right != -1)right += grid[i][j];
        int down = rec(i + 1,j, (grid[i][j] == 0)? k : k - 1,grid,Dp);
        if(down != -1)down += grid[i][j];
        
        return  Dp[i][j][k] = max(right,down);        
    }
    int maxPathScore(vector<vector<int>>& grid, int k) {
        vector<vector<vector<int>>>Dp(grid.size(),vector<vector<int>>(grid[0].size(),vector<int>(k + 5,-10)));
        return rec(0,0,k,grid,Dp);
    }
};