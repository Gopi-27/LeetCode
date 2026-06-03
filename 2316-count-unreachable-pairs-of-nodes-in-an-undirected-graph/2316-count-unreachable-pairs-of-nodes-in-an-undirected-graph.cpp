class Solution {
public:
    int DFS(int v,vector<bool>& Vis,vector<vector<int>>& Adj){
        Vis[v] = 1;
        int l = 1;
        for(int& u : Adj[v])if(!Vis[u])l += DFS(u,Vis,Adj);
        return l;
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int>>Adj(n);
        for(vector<int>& e : edges){
            Adj[e[0]].push_back(e[1]);
            Adj[e[1]].push_back(e[0]);
        }
        long long ans = 0;
        vector<bool>Vis(n);
        for(int i = 0; i < n; i++){
            if(!Vis[i]){
                int l = DFS(i,Vis,Adj);
                // cout << l << "- > ";
                ans += 1ll * l * (n - l);
            }
        }
        return ans/2;
    }
};