class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>Adj(n);
        for(vector<int>& t : times){
            Adj[t[0] - 1].push_back({t[1] - 1,t[2]});
        }
        vector<int>Dis(n,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>>pq;
        Dis[k - 1] = 0;
        pq.push({0,k - 1});
        while(!pq.empty()){
            int u = pq.top().second;
            int wt = pq.top().first;pq.pop();
            for(pair<int,int>e : Adj[u]){
                if(wt + e.second < Dis[e.first]){
                    Dis[e.first] = wt + e.second;
                    pq.push({Dis[e.first],e.first});
                }
            }
        }
        int maxi = 0;
        for(int i = 0; i < n; i++){
            if(Dis[i] == INT_MAX)return -1;
            maxi = max(maxi,Dis[i]);
        }
        return maxi;
    }
};