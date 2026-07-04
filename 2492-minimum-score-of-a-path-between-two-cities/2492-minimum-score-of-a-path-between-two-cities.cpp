class Solution {
public:
    void DFS(int v,vector<vector<pair<int,int>>>& Adj,vector<bool>& Vis){
        Vis[v] = 1;
        for(pair<int,int>& p : Adj[v]){
            int u = p.first;
            if(!Vis[u])DFS(u,Adj,Vis);
        }
        return;
    }
    int minScore(int n, vector<vector<int>>& roads) {
        vector<bool>Vis(n + 1);
        vector<vector<pair<int,int>>>Adj(n + 1);
        for(vector<int>& r : roads){
            Adj[r[0]].push_back({r[1],r[2]});
            Adj[r[1]].push_back({r[0],r[2]});
        }
        DFS(1,Adj,Vis);
        int ans = INT_MAX;
        for(vector<int>& r : roads){
            if(Vis[r[0]] && Vis[r[1]])ans = min(ans,r[2]);
        }
        return ans;
    }
};