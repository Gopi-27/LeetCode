class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>>Adj(n),ans(n);
        vector<int>InDeg(n);
        for(vector<int>& e : edges){
            int u = e[0];
            int v = e[1];
            Adj[u].push_back(v);
            InDeg[v]++;
        }
        queue<int>Q;
        for(int i = 0; i < n; i++)
            if(InDeg[i] == 0)Q.push(i);
        
        while(!Q.empty()){
            int u = Q.front();Q.pop();
            for(int& v : Adj[u]){
                for(int& from : ans[u]){
                    // if from not present in ans[v] then insert
                    if(find(ans[v].begin(),ans[v].end(),from) == ans[v].end())
                        ans[v].push_back(from);
                }
                ans[v].push_back(u);
                InDeg[v]--;
                if(InDeg[v] == 0)Q.push(v);
            }
        }        
        for(int i = 0; i < n; i++)
            sort(ans[i].begin(),ans[i].end());
        return ans;
    }
};