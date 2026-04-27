class Solution {
public:
    vector<bool>Left = {0,1,0,1,0,1,0};
    vector<bool>Right = {0,1,0,0,1,0,1};
    vector<bool>Up = {0,0,1,0,0,1,1};
    vector<bool>Down = {0,0,1,1,1,0,0};

    bool rec(int i,int j,vector<vector<bool>>& Vis,vector<vector<int>>& grid,int n,int m){
        if(i == n - 1 && j == m - 1)return true;
        Vis[i][j] = true;
        bool ans = false;
        // right
        if(j + 1 < m && !Vis[i][j + 1] && Right[grid[i][j]] && Left[grid[i][j + 1]])ans |= rec(i,j + 1,Vis,grid,n,m);
        // left
        if(j - 1 >= 0 && !Vis[i][j - 1] && Left[grid[i][j]] && Right[grid[i][j - 1]])ans |= rec(i,j - 1,Vis,grid,n,m);
        // up
        if(i - 1 >= 0 && !Vis[i - 1][j] && Up[grid[i][j]] && Down[grid[i - 1][j]])ans |= rec(i - 1,j,Vis,grid,n,m);
        //down
        if(i + 1 < n && !Vis[i + 1][j] && Down[grid[i][j]] && Up[grid[i + 1][j]])ans |= rec(i + 1,j,Vis,grid,n,m);
        return ans;
    }
    bool hasValidPath(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>>Vis(n,vector<bool>(m));
        return rec(0,0,Vis,grid,n,m);
    }
};