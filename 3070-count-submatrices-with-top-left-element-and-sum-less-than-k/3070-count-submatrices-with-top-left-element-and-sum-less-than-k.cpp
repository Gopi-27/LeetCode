class Solution {
public:
    int GetVal(int i,int j,vector<vector<int>>& grid){
        if(i < 0 || j < 0)return 0;
        if(i >= grid.size() || j >= grid[0].size())return 0;
        return grid[i][j];
    }
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                grid[i][j] += GetVal(i,j - 1,grid) + GetVal(i - 1,j,grid) - GetVal(i - 1, j - 1,grid);
            }
        }
        int cnt = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] <= k)cnt++;
            }
        }
        return cnt;
    }
};