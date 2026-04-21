class Solution {
public:
    void DFS(int v,vector<vector<int>>& Adj,vector<bool>& Vis,vector<int>& path){
        Vis[v] = true;
        path.push_back(v);
        for(auto u : Adj[v]){
            if(!Vis[u]){
                DFS(u,Adj,Vis,path);
            }
        }
        return;
    }
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        vector<vector<int>>Adj(n);
        for(auto e : allowedSwaps){
            Adj[e[0]].push_back(e[1]);
            Adj[e[1]].push_back(e[0]);
        }
        vector<bool>Vis(n);
        vector<vector<int>>Mat;
        for(int i = 0; i < n; i++){
            if(!Vis[i]){
                vector<int>path;
                DFS(i,Adj,Vis,path);
                Mat.push_back(path);
            }
        }
        int ans = 0;
        for(auto& v : Mat){
            unordered_map<int,int>src,tar;
            for(auto& idx : v){
                cout << idx << " ";
                src[source[idx]]++;
                tar[target[idx]]++;
            }
            cout << endl;
            for(auto& b : src){
                ans += max(0,b.second - tar[b.first]);
            }
        }
        return ans;
    }
};