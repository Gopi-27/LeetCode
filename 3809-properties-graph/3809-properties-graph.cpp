class Solution {
public:
    int CommonCnt(vector<int>& A, vector<int>& B){
        int cnt = 0;
        for(int i = 1; i <= 100; i++)if(A[i] && B[i])cnt++;
        return cnt;
    }
    void DFS(int v,vector<bool>& Vis,vector<vector<int>>& Adj){
        Vis[v] = 1;
        for(int& u : Adj[v])if(!Vis[u])DFS(u,Vis,Adj);
    }
    int numberOfComponents(vector<vector<int>>& properties, int k) {
        int n = properties.size();
        vector<vector<int>>Frr(n,vector<int>(101));
        for(int i = 0; i < n; i++)for(int& e : properties[i])Frr[i][e] = 1;
        vector<vector<int>>Adj(n);
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                if(CommonCnt(Frr[i],Frr[j]) >= k){
                    Adj[i].push_back(j);
                    Adj[j].push_back(i);
                }
            }
        }
        vector<bool>Vis(n);
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(!Vis[i]){
                DFS(i,Vis,Adj);
                ans++;
            }
        }
        return ans;
    }
};