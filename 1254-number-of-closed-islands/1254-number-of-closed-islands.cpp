class Solution {
public:
    void DFS(int i,int j,vector<vector<bool>>& Vis,vector<vector<int>>& grid){
        Vis[i][j] = 1;
        if(j + 1 < Vis[0].size() && !Vis[i][j + 1] && !grid[i][j + 1])DFS(i,j + 1,Vis,grid);
        if(i + 1 < Vis.size() && !Vis[i + 1][j] && !grid[i + 1][j])DFS(i + 1,j,Vis,grid);
        if(j - 1 >= 0 && !Vis[i][j - 1] && !grid[i][j - 1])DFS(i,j - 1,Vis,grid);
        if(i - 1 >= 0 && !Vis[i - 1][j] && !grid[i - 1][j])DFS(i - 1,j,Vis,grid);
        return;
    }
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>>Vis(n,vector<bool>(m));
        for(int j = 0; j < m; j++){
            if(!Vis[0][j] && !grid[0][j])DFS(0,j,Vis,grid);
            if(!Vis[n - 1][j] && !grid[n - 1][j])DFS(n - 1,j,Vis,grid);
        }
        for(int i = 0; i < n; i++){
            if(!Vis[i][0] && !grid[i][0])DFS(i,0,Vis,grid);
            if(!Vis[i][m - 1] && !grid[i][m - 1])DFS(i,m - 1,Vis,grid);
        }
        int ans = 0;
        for(int i = 1; i < n - 1; i++){
            for(int j = 1; j < m - 1; j++){
                if(!grid[i][j] && !Vis[i][j]){
                    ans++;
                    DFS(i,j,Vis,grid);
                }
            }
        }
        return ans;
    }
};