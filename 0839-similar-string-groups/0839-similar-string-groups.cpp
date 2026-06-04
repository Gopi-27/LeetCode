class Solution {
public:
    int findPar(int u,vector<int>& Par){
        if(u == Par[u])return u;
        return Par[u] = findPar(Par[u],Par);
    }
    void Union(int u,int v,vector<int>& Par,vector<int>& Rnk){
        int pu = findPar(u,Par);
        int pv = findPar(v,Par);
        if(pu == pv)return;
        if(Rnk[pu] < Rnk[pv])Par[pu] = pv;
        else if(Rnk[pv] < Rnk[pu])Par[pv] = pu;
        else{
            Par[pu] = pv;
            Rnk[pv]++;
        }
    }
    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        vector<int>Par(n),Rnk(n);
        for(int i = 0; i < n; i++)Par[i] = i;
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                int mcnt = 0;
                vector<int>Idx;
                for(int k = 0; k < strs[i].size(); k++){
                    if(strs[i][k] != strs[j][k]){
                        mcnt++;
                        if(mcnt >= 3)break;
                        Idx.push_back(k);
                    }
                }
                if(mcnt <= 2){
                    Union(i,j,Par,Rnk);
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < n; i++)if(i == Par[i])ans++;
        return ans;
    }
};