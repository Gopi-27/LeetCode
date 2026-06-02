class Solution {
public:
    string findPar(string u,map<string,string>& Par){
        if(Par[u] == u)return u;
        return Par[u] = findPar(Par[u],Par);
    }
    void Union(string& u,string& v,map<string,string>& Par,map<string,int>& Rnk){
        string up = findPar(u,Par);
        string vp = findPar(v,Par);
        if(Rnk[up] < Rnk[vp])Par[up] = Par[vp];
        else if(Rnk[vp] < Rnk[up])Par[vp] = Par[up];
        else{
            Par[up] = Par[vp];
            Rnk[vp]++;
        }
        return ;
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        map<string,string>Par;
        map<string,int>Rnk;
        map<string,string>Own;
        int n = accounts.size();
        for(int i = 0; i < n; i++){
            Own[accounts[i][1]] = accounts[i][0];

            if(!Par.count(accounts[i][1]))Par[accounts[i][1]] = accounts[i][1];
            for(int j = 2; j < accounts[i].size(); j++){
                Own[accounts[i][j]] = accounts[i][0];

                if(!Par.count(accounts[i][j]))Par[accounts[i][j]] = accounts[i][j];
                Union(accounts[i][1],accounts[i][j],Par,Rnk);
            }
        }
        for(auto b : Par)findPar(b.first,Par);
        vector<vector<string>>ans;
        for(auto& b : Par){
            if(b.first == b.second){
                ans.push_back({Own[b.second]});
                int i = ans.size() - 1;
                for(auto& x : Par)if(x.second == b.second)ans[i].push_back(x.first);
            }
        }
        return ans;
    }
};