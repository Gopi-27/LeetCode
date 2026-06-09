class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>>Vis(n,vector<bool>(m));
        vector<vector<pair<int,int>>>Dp(n,vector<pair<int,int>>(m));
        int ans = 0,cnt = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!Vis[i][j] && grid[i][j]){
                    queue<pair<int,int>>Q;
                    cnt++;
                    vector<pair<int,int>>Idx;
                    Vis[i][j] = 1;
                    Q.push({i,j});
                    while(!Q.empty()){
                        Idx.push_back(Q.front());
                        int r = Q.front().first;
                        int c = Q.front().second;Q.pop();
                        if(c + 1 < m && !Vis[r][c + 1] && grid[r][c + 1])Q.push({r,c + 1});
                        if(c + 1 < m && !Vis[r][c + 1] && grid[r][c + 1])Vis[r][c + 1] = 1;
                        if(c - 1 >= 0 && !Vis[r][c - 1] && grid[r][c - 1])Q.push({r,c - 1});
                        if(c - 1 >= 0 && !Vis[r][c - 1] && grid[r][c - 1])Vis[r][c - 1] = 1;
                        if(r - 1 >= 0 && !Vis[r - 1][c] && grid[r - 1][c])Q.push({r - 1,c});
                        if(r - 1 >= 0 && !Vis[r - 1][c] && grid[r - 1][c])Vis[r - 1][c] = 1;
                        if(r + 1 < n && !Vis[r + 1][c] && grid[r + 1][c])Q.push({r + 1,c});
                        if(r + 1 < n && !Vis[r + 1][c] && grid[r + 1][c])Vis[r + 1][c] = 1;
                    }
                    int l = Idx.size();
                    ans = max(ans,l);
                    for(pair<int,int>& p : Idx)Dp[p.first][p.second] = {l,cnt};
                }
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!grid[i][j]){
                    int val = 1;
                    set<int>st;
                    if(j + 1 < m)val += Dp[i][j + 1].first;
                    if(j + 1 < m)st.insert(Dp[i][j + 1].second);
                    if(j - 1 >= 0 && !st.count(Dp[i][j - 1].second))val += Dp[i][j - 1].first;
                    if(j - 1 >= 0)st.insert(Dp[i][j - 1].second);
                    if(i - 1 >= 0 && !st.count(Dp[i - 1][j].second))val += Dp[i - 1][j].first;
                    if(i - 1 >= 0)st.insert(Dp[i - 1][j].second);
                    if(i + 1 < n && !st.count(Dp[i + 1][j].second))val += Dp[i + 1][j].first;
                    ans = max(ans,val);
                }
            }
        }
        return ans;
    }
};