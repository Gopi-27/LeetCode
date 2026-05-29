class Solution {
public:
    long long ans = 0;
    int DFS(int v,vector<bool>& Vis,vector<vector<int>>& Adj,int seats){
        Vis[v] = 1;
        int cnt = 1;
        for(int& u : Adj[v]){
            if(!Vis[u]){
                cnt += DFS(u,Vis,Adj,seats);
            }
        }
        ans += cnt/seats;
        if(cnt % seats != 0)ans++;
        return cnt;
    }
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n = roads.size() + 1;
        vector<vector<int>>Adj(n);
        for(vector<int>& r : roads){
            Adj[r[0]].push_back(r[1]);
            Adj[r[1]].push_back(r[0]);
        }
        vector<bool>Vis(n);
        DFS(0,Vis,Adj,seats);
        ans -= n/seats;
        if(n % seats != 0)ans--;
        return ans;
    }
};