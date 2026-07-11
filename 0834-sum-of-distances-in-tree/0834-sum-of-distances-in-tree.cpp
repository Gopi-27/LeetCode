class Solution {
public:
    pair<int,int> DFS(int v,vector<vector<int>>& Adj,vector<bool>& Vis,vector<int>& Ans,vector<int>& Cnt){
        Vis[v] = 1;
    
        int ans = 0;
        int cnt = 0;
        for(int& u : Adj[v]){
            if(!Vis[u]){
                pair<int,int>p = DFS(u,Adj,Vis,Ans,Cnt);
                ans += p.first + p.second;
                cnt += p.second;
            }
        }
        Ans[v] = ans;
        Cnt[v] = cnt + 1;
        return {ans,cnt + 1};
    }
    void rec(int v,vector<vector<int>>& Adj,vector<bool>& Vis,vector<int>& Ans,vector<int>& Cnt){
        Vis[v] = 1;
        for(int& u : Adj[v]){
            if(!Vis[u]){
                Ans[u]  += (Ans[v] - Ans[u] - Cnt[u]) + (Cnt[v] - Cnt[u]);
                // cout << u <<" "<< Ans[u] << endl;
                Cnt[u] = Cnt[v];
                rec(u,Adj,Vis,Ans,Cnt);
            }
        }
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>>Adj(n);
        for(vector<int>& e : edges){
            Adj[e[0]].push_back(e[1]);
            Adj[e[1]].push_back(e[0]);
        }
        vector<bool>Vis(n);
        vector<int>Ans(n),Cnt(n);
        pair<int,int> p = DFS(0,Adj,Vis,Ans,Cnt);
        // for(int i = 0; i < n; i++){
        //     cout << i << " -> " << Ans[i] << " => " << Cnt[i] << endl;
        // }
        for(int i = 0; i < n; i++)Vis[i] = 0;
        rec(0,Adj,Vis,Ans,Cnt);
        
        return Ans;
    }
};