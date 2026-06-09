class Solution {
public:
    void DFS(int i,int j,vector<vector<bool>>& Vis,vector<vector<char>>& grid){
        Vis[i][j] = 1;
        if(j + 1 < Vis[0].size() && grid[i][j + 1] == '1' && !Vis[i][j + 1])DFS(i,j + 1,Vis,grid);
        if(j - 1 >= 0 && grid[i][j - 1] == '1' && !Vis[i][j - 1])DFS(i,j - 1,Vis,grid);
        if(i - 1 >= 0 && grid[i - 1][j] == '1' && !Vis[i - 1][j])DFS(i - 1,j,Vis,grid);
        if(i + 1 < Vis.size() && grid[i + 1][j] == '1' && !Vis[i + 1][j])DFS(i + 1,j,Vis,grid);
        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>>Vis(n,vector<bool>(m));
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!Vis[i][j] && grid[i][j] == '1'){
                    DFS(i,j,Vis,grid);
                    ans++;
                }
            }
        }
        return ans;
    }
};