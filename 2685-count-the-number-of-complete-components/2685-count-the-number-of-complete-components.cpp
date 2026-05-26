class Solution {
public:
    void DFS(int v,vector<int>& lst,vector<bool>& Vis,vector<vector<int>>& Adj){
        Vis[v] = 1;
        lst.push_back(v);
        for(int& u : Adj[v])if(!Vis[u])DFS(u,lst,Vis,Adj);
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<bool>Vis(n);
        vector<vector<int>>Adj(n);
        for(vector<int>& e : edges){
            Adj[e[0]].push_back(e[1]);
            Adj[e[1]].push_back(e[0]);
        }
        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(!Vis[i]){
                vector<int>lst;
                DFS(i,lst,Vis,Adj);
                int len = lst.size();
                bool flag = 1;
                for(int &v : lst)if(1 + Adj[v].size() != len)flag = 0;
                if(flag)cnt++;
            }
        }
        return cnt;
    }
};