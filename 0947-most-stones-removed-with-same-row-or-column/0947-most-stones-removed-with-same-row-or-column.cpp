class Solution {
public:
    void DFS(int v,vector<bool>& Vis,vector<vector<int>>& Adj){
        Vis[v] = 1;
        for(int& u : Adj[v])if(!Vis[u])DFS(u,Vis,Adj);
        return;
    }
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<vector<int>>Adj(n);
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]){
                    Adj[i].push_back(j);
                    Adj[j].push_back(i);
                }
            }
        }
        vector<bool>Vis(n);
        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(!Vis[i]){
                DFS(i,Vis,Adj);
                cnt++;
            }
        }
        return n - cnt;
    }
};