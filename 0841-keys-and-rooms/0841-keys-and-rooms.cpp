class Solution {
public:
    void DFS(vector<vector<int>>& Adj,vector<int>& Vis,int & cnt,int start){
        Vis[start] = 1;
        cnt++;
        for(int i = 0; i < Adj[start].size(); i++){
            if(!Vis[Adj[start][i]])DFS(Adj,Vis,cnt,Adj[start][i]);
        }
        return;
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int cnt = 0;
        int n = rooms.size();
        vector<int>Vis(n,0);
        DFS(rooms,Vis,cnt,0);
        if(cnt == n)return true;
        return false;
    }
};