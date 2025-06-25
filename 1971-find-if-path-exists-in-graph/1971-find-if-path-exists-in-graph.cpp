class Solution {
public:
    bool DFS(vector<vector<int>>& Adj,vector<int>& Vis,int start,int target){
        if(start == target)return true;
        Vis[start] = 1;
        for(int i = 0; i < Adj[start].size(); i++){
            if(!Vis[Adj[start][i]]){
                if(DFS(Adj,Vis,Adj[start][i],target))return true;// return f
            }
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>>Adj(n);
        for(int i = 0; i < edges.size(); i++){
            Adj[edges[i][0]].push_back(edges[i][1]);
            Adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int>Vis(n);
        return DFS(Adj,Vis,source,destination);        
    }
};