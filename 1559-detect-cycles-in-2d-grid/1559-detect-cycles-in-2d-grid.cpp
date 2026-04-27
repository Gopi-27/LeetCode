class Solution {
public:
    vector<pair<int,int>>Dir = {{0,-1},{0,1},{-1,0},{1,0}};
    bool DFS(int i,int j,char& key,vector<vector<int>>& Vis,vector<vector<char>>& grid,int n,int m,int len){
        // cout << i << " " << j << endl;
        len++;
        Vis[i][j] = len;
        for(auto& d : Dir){
            int r = i + d.first;
            int c = j + d.second;
            if(r < n && c < m && r >= 0 && c >= 0){
                if(Vis[r][c] && grid[r][c] == key){
                    if(len - Vis[r][c] >= 3)return true;
                }else{
                    if(grid[r][c] == key)if(DFS(r,c,key,Vis,grid,n,m,len))return true;
                }
            }
        }
        return false;
    }
    bool containsCycle(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>Vis(n,vector<int>(m));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!Vis[i][j])if(DFS(i,j,grid[i][j],Vis,grid,n,m,0))return true;
            }
        }
        return false;
    }
};