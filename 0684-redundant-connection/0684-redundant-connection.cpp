class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<vector<int>>Adj(n);
        vector<int>InDeg(n);
        for(vector<int>& e : edges){
            Adj[e[0]].push_back(e[1]);
            Adj[e[1]].push_back(e[0]);
            InDeg[e[0]]++;
            InDeg[e[1]]++;
        }
        queue<int>Q;
        for(int i = 1; i < n; i++)if(InDeg[i] == 1)Q.push(i);
        while(!Q.empty()){
            int u = Q.front();Q.pop();
            for(int & v : Adj[u]){
                InDeg[v]--;
                if(InDeg[v] == 1)Q.push(v);
            }
        }
        reverse(edges.begin(),edges.end());
        for(vector<int>& e : edges){
            if(InDeg[e[0]] > 1 && InDeg[e[1]] > 1)return e;
        }
        return {};
    }
};