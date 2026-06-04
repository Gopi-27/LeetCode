class Solution {
public:
    int findPar(int u,vector<int>& Par){
        if(u == Par[u])return u;
        return Par[u] = findPar(Par[u],Par);
    }
    void Union(int u,int v,vector<int>& Par,vector<int>& Rnk){
        int up = findPar(u,Par);
        int vp = findPar(v,Par);
        if(up == vp)return;
        if(Rnk[up] < Rnk[vp])Par[up] = vp;
        else if(Rnk[vp] < Rnk[up])Par[vp] = up;
        else{
            Par[vp] = up;
            Rnk[up]++;
        }
    }
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.size();
        vector<int>Par(n),Rnk(n);
        for(int i = 0; i < n; i++)Par[i] = i;
        for(vector<int>& p : pairs)Union(p[0],p[1],Par,Rnk);
        for(int i = 0; i < n; i++)Par[i] = findPar(Par[i],Par);
        map<int,vector<int>>mpp;
        map<int,vector<char>>spp;
        for(int i = 0; i < n; i++){
            mpp[Par[i]].push_back(i);
            spp[Par[i]].push_back(s[i]);
        }
        for(auto& b : mpp)sort(b.second.begin(),b.second.end());
        for(auto& b : spp)sort(b.second.begin(),b.second.end());
        for(auto& b : mpp){
            for(int i = 0; i < b.second.size(); i++){
                s[b.second[i]] = spp[b.first][i];
            }
        }
        return s;
    }
};