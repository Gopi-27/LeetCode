class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<vector<int>>Adj(n);
        for(vector<int>& p : paths){
            Adj[p[0] - 1].push_back(p[1] - 1);
            Adj[p[1] - 1].push_back(p[0] - 1);
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
                    for(int i = 1; i <= 4; i++){
                        if(!(mask & (1 << i))){
                            Col[u] = i;
                            break;
                        }
                    }
                }
            }
        }
        return  Col;
    }
};