class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<bool>>Preq(n,vector<bool>(n));
        for(vector<int>& p : prerequisites)Preq[p[1]][p[0]] = 1;
        for(int t = 0; t < n; t++){
            for(int i = 0; i < n; i++){
                if(Preq[i][t]){
                    for(int j = 0; j < n; j++){
                        if(Preq[t][j]){
                            Preq[i][j] = 1;
                        }
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