class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>>Adj(n);
        for(vector<int>& p : prerequisites)Adj[p[1]].push_back(p[0]);
        vector<vector<bool>>Preq(n,vector<bool>(n));
        for(int i = 0; i < n; i++){
            queue<int>Q;
            Q.push(i);
            Preq[i][i] = 1;
            while(!Q.empty()){
                int u = Q.front();Q.pop();
                for(int& v : Adj[u]){
                    if(!Preq[i][v]){
                        Q.push(v);
                        Preq[i][v] = 1;
                    }
                }
            }
        }
        vector<bool>Ans;// :u -> v:
        for(vector<int>& q : queries){
            if(Preq[q[1]][q[0]])Ans.push_back(1);
            else Ans.push_back(0);
        }
        return Ans;

    }
};