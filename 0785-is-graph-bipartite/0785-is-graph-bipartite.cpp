class Solution {
public:
    bool isBipartite(vector<vector<int>>& Adj) {
        int n = Adj.size();
        vector<int>Col(n);
        for(int i = 0; i < n; i++){
            if(!Col[i]){
                queue<int>Q;
                Q.push(i);
                while(!Q.empty()){
                    int u = Q.front();Q.pop();
                    int mask = 0;
                    for(int& v : Adj[u]){
                        if(!Col[v])Q.push(v);
                        else mask |= (1 << Col[v]);
                    }
                    if((mask & (1 << 1)) && (mask & (1 << 2)))return false;
                    if(mask & (1 << 1))Col[u] = 2;
                    else Col[u] = 1;
                }
            }
        }
        return true;
    }
};