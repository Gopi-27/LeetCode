class Solution {
public:
    long long DFS(int i,int j,vector<vector<int>>& grid,vector<vector<bool>>& Vis){
        Vis[i][j] = 1;
        long long ans = grid[i][j];
        if(j + 1 < grid[0].size() && !Vis[i][j + 1])ans += DFS(i,j + 1,grid,Vis);
        if(j - 1 >= 0 && !Vis[i][j - 1])ans += DFS(i,j - 1,grid,Vis);
        if(i + 1 < grid.size() && !Vis[i + 1][j])ans += DFS(i + 1,j,grid,Vis);
        if(i - 1 >= 0 && !Vis[i - 1][j])ans += DFS(i - 1,j,grid,Vis);
        return ans;

    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>>Vis(n,vector<bool>(m));
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(!grid[i][j])Vis[i][j] = 1;
        int cnt = 0;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(!Vis[i][j])cnt += DFS(i,j,grid,Vis) % k == 0;
            
        return cnt;
            
    }
};