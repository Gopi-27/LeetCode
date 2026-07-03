#define ll long long 

class Solution {
public:
    bool Dijkstras(vector<vector<pair<int,int>>>& Adj,int n,ll key,ll k){
        vector<ll>Dis(n,LLONG_MAX);
        priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>pq;
        Dis[0] = 0;
        pq.push({0,0});
        while(!pq.empty()){
            ll wt = pq.top().first;
            ll u = pq.top().second;pq.pop();
            for(pair<int,int>& p : Adj[u]){
                int v = p.first;
                ll cost = p.second;
                if(cost >= key && Dis[v] > wt + cost){
                    Dis[v] = wt + cost;
                    pq.push({Dis[v],v});
                }
            }
        }
        return Dis[n - 1] <= k;
    }
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();
        vector<vector<pair<int,int>>>Adj(n);
        for(vector<int>& e : edges)if(online[e[0]] && online[e[1]])Adj[e[0]].push_back({e[1],e[2]});
        ll low = 1;
        ll high = 1e9;
        if(!Dijkstras(Adj,n,0,k))return -1;
        while(low <= high){
            ll mid = (low + high) >> 1;
            if(Dijkstras(Adj,n,mid,k))low = mid + 1;
            else high = mid - 1;
        }
        return high;        
    }
};