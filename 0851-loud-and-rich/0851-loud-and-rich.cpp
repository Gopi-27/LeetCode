class Solution {
public:
    int DFS(int v,vector<vector<int>>&Adj,vector<int>&quiet,vector<int>&Ans){

        if(Ans[v] != -1){
            return Ans[v];
        }
        int p = v;
        for(auto i : Adj[v]){
            int x = DFS(i,Adj,quiet,Ans);
            p = (quiet[x] > quiet[p])?p:x;
        }
        Ans[v] = p;
        return p;
    }
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        vector<vector<int>>Adj(n);
        for(auto r : richer){
            Adj[r[1]].push_back(r[0]);
        }
        vector<int>Ans(n,-1);
        for(int i = 0; i < n; i++){
            if(Ans[i] == -1){
                Ans[i] = DFS(i,Adj,quiet,Ans);
            }
        }
        return Ans;
    }
};