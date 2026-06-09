class Solution {
public:
    pair<int,int> DFS(int i,int j,vector<vector<bool>>& Vis,vector<vector<int>>& land){
        Vis[i][j] = 1;
        pair<int,int>ans = {i,j};
        if(j + 1 < Vis[0].size() && !Vis[i][j + 1] && land[i][j + 1]){
            pair<int,int> p = DFS(i,j + 1,Vis,land);
            ans.first = max(ans.first,p.first);
            ans.second = max(ans.second,p.second);
        }
        if(i + 1 < Vis.size() && !Vis[i + 1][j] && land[i + 1][j]){
            pair<int,int> p = DFS(i + 1,j,Vis,land);
            ans.first = max(ans.first,p.first);
            ans.second = max(ans.second,p.second);
        }
        return ans;
    }
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int n = land.size();
        int m = land[0].size();
        vector<vector<bool>>Vis(n,vector<bool>(m));
        vector<vector<int>>Ans;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(land[i][j] && !Vis[i][j]){
                    pair<int,int> p = DFS(i,j,Vis,land);
                    Ans.push_back({i,j,p.first,p.second});
                }
            }
        }
        return Ans;
    }
};