class Solution {
public:
    bool DFS(int i,int j,vector<vector<bool>>& Vis,vector<vector<int>>& grid1,vector<vector<int>>& grid2){
        Vis[i][j] = 1;
        bool flag = 1;
        if(!grid1[i][j])flag = 0;
        if(j + 1 < Vis[0].size() && !Vis[i][j + 1] && grid2[i][j + 1])flag &= DFS(i,j + 1,Vis,grid1,grid2);
        if(j - 1 >= 0 && !Vis[i][j - 1] && grid2[i][j - 1])flag &= DFS(i,j - 1,Vis,grid1,grid2);
        if(i - 1 >= 0 && !Vis[i - 1][j] && grid2[i - 1][j])flag &= DFS(i - 1,j,Vis,grid1,grid2);
        if(i + 1 < Vis.size() && !Vis[i + 1][j] && grid2[i + 1][j])flag &= DFS(i + 1,j,Vis,grid1,grid2);
        return flag;
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n = grid1.size();
        int m = grid1[0].size();
        vector<vector<bool>>Vis(n,vector<bool>(m));
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!Vis[i][j] && grid2[i][j]){
                    ans += DFS(i,j,Vis,grid1,grid2);
                }
            }
        }
        return ans;
    }
};