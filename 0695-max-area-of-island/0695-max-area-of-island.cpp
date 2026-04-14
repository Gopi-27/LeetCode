class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>>Vis(n,vector<bool>(m));
        int maxi = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!grid[i][j] || Vis[i][j])continue;
                queue<pair<int,int>>Q;
                Q.push({i,j});
                int ans = 0;
                while(!Q.empty()){
                    int x = Q.front().first;
                    int y = Q.front().second;Q.pop();
                    Vis[x][y] = true;
                    ans++;
                    //four directions
                    if(y + 1 < m && grid[x][y + 1] && !Vis[x][y + 1])Q.push({x,y + 1});
                    if(y - 1 >= 0 && grid[x][y - 1] && !Vis[x][y - 1])Q.push({x,y - 1});
                    if(x + 1 < n && grid[x + 1][y] && !Vis[x + 1][y])Q.push({x + 1,y});
                    if(x - 1 >= 0 && grid[x - 1][y] && !Vis[x - 1][y])Q.push({x - 1,y});
                }
                maxi = max(maxi,ans);

            }
        }
        return maxi;
    }
};