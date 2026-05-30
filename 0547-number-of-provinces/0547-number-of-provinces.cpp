class Solution {
public:
    void DFS(int v,vector<bool>& Vis, vector<vector<int>>& Adj){
        Vis[v] = 1;
        for(int j = 0; j < Adj[v].size(); j++)if(Adj[v][j] && !Vis[j])DFS(j,Vis,Adj);
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool>Vis(n);
        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(!Vis[i]){
                DFS(i,Vis,isConnected);
                cnt++;
            }
        }
        return cnt;
    }
};