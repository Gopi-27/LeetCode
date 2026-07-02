class Solution {
public:
    int Dp[52][52][102];
    bool DFS(int i,int j,int health, vector<vector<int>>& grid,vector<vector<bool>>& Vis){
        if(health <= 0)return false;
        if(i == grid.size() - 1&& j == grid[0].size() - 1)return true;
        if(Dp[i][j][health] != -1)return Dp[i][j][health];
        Vis[i][j] = 1;
        bool flag = 0;
        if(j - 1 >= 0 && !Vis[i][j - 1])
            flag |= DFS(i,j - 1,(grid[i][j - 1] == 0) ? health: health - 1,grid,Vis);

        if(!flag && j + 1 < grid[0].size() && !Vis[i][j + 1])
            flag |= DFS(i,j + 1,(grid[i][j + 1] == 0) ? health : health - 1,grid,Vis);

        if(!flag && i - 1 >= 0 && !Vis[i - 1][j])
            flag |= DFS(i - 1,j,(grid[i - 1][j] == 0) ? health : health - 1,grid,Vis);

        if(!flag && i + 1 < grid.size() && !Vis[i + 1][j])
            flag |= DFS(i + 1,j,(grid[i + 1][j] == 0) ? health : health - 1,grid,Vis);
        Vis[i][j] = 0;
        return Dp[i][j][health] = flag;
    }
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        vector<vector<bool>>Vis(grid.size(),vector<bool>(grid[0].size()));
        memset(Dp,-1,sizeof(Dp));
        return DFS(0,0,(grid[0][0] == 0) ? health: health - 1 ,grid,Vis);
    }
};