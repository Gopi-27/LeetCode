class Solution {
public:
    int DFS(int v,vector<bool>& Vis,vector<vector<pair<int,int>>>&  Adj){
        Vis[v] = 1;
        int ans = 0;
        for(pair<int,int>& e : Adj[v]){
            if(!Vis[e.first]){
                ans += e.second + DFS(e.first,Vis,Adj);
            }
        }
        return ans;
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int,int>>>Adj(n);
        for(vector<int>& c : connections){
            Adj[c[0]].push_back({c[1],1});
            Adj[c[1]].push_back({c[0],0});
        }
        vector<bool>Vis(n);
        return DFS(0,Vis,Adj);
    }
};