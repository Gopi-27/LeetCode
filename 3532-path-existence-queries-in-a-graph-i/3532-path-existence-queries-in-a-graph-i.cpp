class Solution {
public:
    int findPar(int u,vector<int>& Par){
        if(Par[u] == u)return u;
        return Par[u] = findPar(Par[u],Par);
    }
    void Union(int u,int v,vector<int>& Par,vector<int>& Rnk){
        int pu = findPar(u,Par);
        int pv = findPar(v,Par);
        if(Rnk[pu] < Rnk[pv])Par[pv] = pu;
        else if(Rnk[pv] < Rnk[pu])Par[pu] = pv;
        else{
            Par[pu] = pv;
            Rnk[pu]++;
        }
    }
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int>Par(n);
        for(int i = 0; i < n; i++)Par[i] = i;
        vector<int>Rnk(n);
        for(int i = 0; i < n - 1; i++){
            if(nums[i + 1] - nums[i] <= maxDiff)Union(i,i + 1,Par,Rnk);
        }
        vector<bool>Ans;
        for(vector<int>& q : queries){
            if(findPar(q[0],Par) == findPar(q[1],Par))Ans.push_back(true);
            else Ans.push_back(false);
        }
        return Ans;
    }
};