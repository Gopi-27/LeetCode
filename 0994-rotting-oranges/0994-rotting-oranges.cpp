class Solution {
public:
    bool CanRotten(vector<vector<int>>& grid,int i,int j,int n,int m){
        bool flag = 0;
        if(j > 0 && grid[i][j - 1] == 2)flag = 1;
        if(j < m - 1 && grid[i][j + 1] == 2)flag = 1;
        if(i > 0 && grid[i - 1][j] == 2)flag = 1;
        if(i < n - 1 && grid[i + 1][j] == 2)flag = 1;
        if(flag)grid[i][j] = 27;
        return flag;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int k = 0;
        int n = grid.size();
        int m = grid[0].size();
        while(1){
            int flag = 0;
            for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++){
                    if(grid[i][j] == 1 && CanRotten(grid,i,j,n,m)){
                        flag++;
                    }
                }
            }
            if(!flag)break;
            for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++){
                    if(grid[i][j] == 27)grid[i][j] = 2;
                }
            }
            k++;
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1)return -1;
            }
        }
        return k;
    }
};