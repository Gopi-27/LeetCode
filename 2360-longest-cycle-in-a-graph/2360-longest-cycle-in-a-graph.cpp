class Solution {
public:
    int DFS(int v,vector<bool>& Vis,vector<int>& edges){
        Vis[v] = 1;
        int cnt = 1;
        if(edges[v] != -1 && !Vis[edges[v]])cnt += DFS(edges[v],Vis,edges);
        return cnt;
    }
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<int>InDeg(n);
        for(int i = 0; i < n; i++)if(edges[i] != -1)InDeg[edges[i]]++;
        queue<int>Q;
        for(int i = 0; i < n; i++)if(!InDeg[i])Q.push(i);
        vector<bool>Vis(n);
        while(!Q.empty()){
            int u = Q.front();Q.pop();
            Vis[u] = 1;
            int v = edges[u];
            if(v == -1)continue;
            InDeg[v]--;
            if(!InDeg[v])Q.push(v);
        }
        int ans = -1;
        for(int i = 0; i < n; i++){
            if(!Vis[i]){
                int val = DFS(i,Vis,edges);
                ans = max(ans,val);
            }
        } 
        return ans;                       
    }
};