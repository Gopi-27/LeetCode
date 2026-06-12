class Solution {
public:
    int mod = 1e9 + 7;
    vector<int>binPow;

    int KthAncestor(int node, int k,vector<vector<int>>& Par) {
        int bin = 0;
        while(k > 0){
            if(node == -1)return node;
            if(k & 1)node = Par[node][bin];
            k >>= 1;
            bin++;
        }
        return node;
    }

    int LCA(int u,int v,vector<vector<int>>& Par,vector<int>& Level){
        if(Level[u] > Level[v])u = KthAncestor(u,Level[u] - Level[v],Par);
        else v = KthAncestor(v,Level[v] - Level[u],Par);
        // cout << u <<  " = > " << v << endl;
        if(u == v)return u;
        for(int i = 0; i < 20; i++){
            if(Par[u][i] == Par[v][i]){
                if(i == 0)return Par[u][i];
                return LCA(Par[u][i - 1],Par[v][i - 1],Par,Level);
            }
        }
        return 1;
    }
    int Arrange(int u,int v,vector<vector<int>>& Par,vector<int>& Level){
        int lca = LCA(u,v,Par,Level);
        int k = Level[u] + Level[v] - 2 * Level[lca];
        // cout << lca << "- > " << k << endl;
        if(k <= 0)return 0;
        return binPow[k - 1];
    }
    
    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        int n = edges.size() + 1;
        vector<vector<int>>Par(n + 1,vector<int>(20));
        vector<int>Level(n + 1);
        vector<vector<int>>Adj(n + 1);

        for(vector<int>& e : edges){
            Adj[e[0]].push_back(e[1]);
            Adj[e[1]].push_back(e[0]);
        }

        vector<bool>Vis(n + 1);
        int l = 1;
        Par[1][0] = -1;
        Vis[1] = 1;
        queue<int>Q;
        Q.push(1);
        while(!Q.empty()){
            int sz = Q.size();
            for(int i = 0; i < sz; i++){
                int u = Q.front();Q.pop();
                for(int& v : Adj[u]){
                    if(!Vis[v]){
                        Vis[v] = 1;
                        Par[v][0] = u;
                        Q.push(v);
                        Level[v] = l;
                    }
                }
            }
            l++;
        }
        
        for(int j = 1; j < 20; j++){
            for(int i = 1; i <= n; i++){
                if(Par[i][j - 1] == -1)Par[i][j] = -1;
                else Par[i][j] = Par[Par[i][j - 1]][j - 1];
            }
        }
        binPow.resize(n + 1);
        binPow[0] = 1;
        for(int i = 1; i <= n; i++){
            binPow[i] = (2ll * binPow[i - 1]) % mod;
            // cout << binPow[i] << " ";
        }
        vector<int>Ans;
        for(vector<int>& q : queries){
            Ans.push_back(Arrange(q[0],q[1],Par,Level));
        }
        return Ans;
    }
};