class Solution {
public:
    int mod = 1e9 + 7;
    int DFS(int v,vector<bool>& Vis,vector<vector<int>>& Adj){
        Vis[v] = true;
        int ans = 0;
        for(auto& u : Adj[v]){
            if(!Vis[u]){
                ans = max(ans, 1  + DFS(u,Vis,Adj));
            }
        }
        return ans;
    }
    int rec(int i,int path,int dep,vector<vector<int>>& Dp){
        if(i >= dep){
            return path == 1;
        }
        if(Dp[i][path] != -1)return Dp[i][path];

        int ans = rec(i + 1,(1 + path) % 2,dep,Dp);
        ans = (ans + rec(i + 1,path,dep,Dp)) % mod;
        return Dp[i][path] = ans;
    }
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<vector<int>>Adj(n + 1);
        for(auto& e : edges){
            Adj[e[0]].push_back(e[1]);
            Adj[e[1]].push_back(e[0]);
        }
        vector<bool>Vis(n + 1);
        int dep = DFS(1,Vis,Adj);
        vector<vector<int>>Dp(dep,vector<int>(2,-1));
        return rec(0,0,dep,Dp);
    }
};