class Solution {
public:
    int KthAncestor(int node, int k,vector<vector<int>>& Par) {
        if(k == 0)return node;
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
        if(u == v)return u;
        for(int i = 0; i < 20; i++){
            if(Par[u][i] == Par[v][i]){
                if(i == 0)return Par[u][i];
                return LCA(Par[u][i - 1],Par[v][i - 1],Par,Level);
            }
        }
        return 0;        
    }
    int ChangeWts(int u,int v,vector<vector<int>>& Par,vector<vector<int>>& Frr,vector<int>& Level){
        vector<int>F(27);
        int lca = LCA(u,v,Par,Level);
        int maxi = 0;
        int tot = 0;
        for(int i = 0; i < 27; i++){
            F[i] = Frr[u][i] + Frr[v][i] - 2 * Frr[lca][i];
            maxi = max(maxi,F[i]);
            tot += F[i];
        }
        return tot - maxi;
    }
    vector<int> minOperationsQueries(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        
        vector<vector<int>>Par(n,vector<int>(20));
        vector<vector<pair<int,int>>>Adj(n);
        for(vector<int>& e : edges){
            Adj[e[0]].push_back({e[1],e[2]});
            Adj[e[1]].push_back({e[0],e[2]});
        }

        vector<vector<int>>Frr(n,vector<int>(27));
        vector<int>Level(n);
        vector<bool>Vis(n);
        queue<int>Q;
        Q.push(0);
        Vis[0] = 1;
        Par[0][0] = -1;
        int l = 1;
        while(!Q.empty()){
            int sz = Q.size();
            for(int i = 0; i < sz; i++){
                int u = Q.front(); Q.pop();
                for(pair<int,int>& p : Adj[u]){
                    int v = p.first;
                    int w = p.second;
                    if(!Vis[v]){
                        Par[v][0] = u;
                        Vis[v] = 1;
                        Q.push(v);
                        Frr[v] = Frr[u];
                        Frr[v][w]++;
                        Level[v] = l;
                    }
                }
            }
            l++;
        }
        
        for(int j = 1; j < 20; j++){
            for(int i = 0; i < n; i++){
                if(Par[i][j - 1] == -1)Par[i][j] = -1;
                else Par[i][j] = Par[Par[i][j - 1]][j - 1];
            }
        }
        vector<int>Ans;
        for(vector<int>& q : queries){
            Ans.push_back(ChangeWts(q[0],q[1],Par,Frr,Level));
        }

        return Ans;

    }
};