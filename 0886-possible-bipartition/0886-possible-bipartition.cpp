class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>>Adj(n);
        for(vector<int>& d : dislikes){
            Adj[d[0] - 1].push_back(d[1] - 1);
            Adj[d[1] - 1].push_back(d[0] - 1);
        }
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