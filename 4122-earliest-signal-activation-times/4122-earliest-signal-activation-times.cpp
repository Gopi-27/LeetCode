class Solution {
public:
    vector<long long> earliestActivationTimes(int n, vector<vector<int>>& edges, vector<int>& reqSig) {
        vector<vector<pair<int,int>>>Adj(n);
        for(vector<int>& e : edges)Adj[e[0]].push_back({e[1],e[2]});
        vector<long long>Ans(n,LLONG_MAX);

        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>pq;
        for(auto& e : Adj[0])pq.push({e.second,e.first});
        
        reqSig[0] = 0;
        while(!pq.empty()){
            long long wt = pq.top().first;
            int u = pq.top().second; pq.pop();
            reqSig[u]--;
            if(reqSig[u] == 0){
                Ans[u] = wt;
                for(auto& e : Adj[u]){
                    int v = e.first;
                    int d = e.second;
                    pq.push({0ll + wt + d,v});
                }
            }
        }
        Ans[0] = 0;
        for(int i = 1; i < n; i++)if(Ans[i] == LLONG_MAX)Ans[i] = -1;
        return Ans;
    }
};