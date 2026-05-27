class Solution {
public:
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
        vector<vector<pair<int,int>>>Adj(n);
        for(vector<int>& e : edges){
            Adj[e[0]].push_back({e[1],e[2]});
            Adj[e[1]].push_back({e[0],e[2]});
        }
        vector<int>Dis(n,INT_MAX);
        Dis[0] = 0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,0});
        while(!pq.empty()){
            int wt = pq.top().first;
            int u = pq.top().second;pq.pop();
            if(wt > Dis[u])continue;
            for(pair<int,int>& e : Adj[u]){
                if(wt + e.second < Dis[e.first] && disappear[e.first] > wt + e.second){
                    Dis[e.first] = wt + e.second;
                    pq.push({Dis[e.first],e.first});
                }
            }
        }
        for(int i = 0; i < n; i++){
            if(Dis[i] == INT_MAX)Dis[i] = -1;
        }
        return Dis;
    }
};