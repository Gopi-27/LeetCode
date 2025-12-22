class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>>Adj(n);
        for(vector<int>& e : invocations){
            int u = e[0];
            int v = e[1];
            Adj[u].push_back(v);
        }
        vector<bool> Block(n);
        queue<int>Q;
        Q.push(k);
        Block[k] = true;
        while(!Q.empty()){
            int u = Q.front();Q.pop();
            for(int & v : Adj[u]){
                if(!Block[v]){
                    Block[v] = 1;
                    Q.push(v);
                }
            }
        }
        vector<int>NotBlock;
        vector<bool>Vis(n);
        for(int i = 0; i < n; i++){
            if(!Block[i]){
                if(!Vis[i]){
                    // go and visit, if you try to meet bloked just return {};
                    Q.push(i);
                    Vis[i] = 1;
                    while(!Q.empty()){
                        int u = Q.front();Q.pop();
                        NotBlock.push_back(u);
                        for(int &v : Adj[u]){
                            if(Block[v]){
                                vector<int>ans(n);
                                for(int l = 0; l < n; l++)ans[l] = l;
                                return ans;
                            }
                            if(!Vis[v]){
                                Vis[v] = 1;
                                Q.push(v);
                            }
                        }  
                    }
                }
            }
        }

        return NotBlock;
    }
};