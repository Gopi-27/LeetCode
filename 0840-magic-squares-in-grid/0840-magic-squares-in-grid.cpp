class Solution {
public:
    int IsValid(int m,int n,vector<vector<int>>& grid){
        int mask = 1;
        vector<int>Row(3);
        for(int i = m - 2; i <= m; i++){
            for(int j = n - 2; j <= n; j++){
                if(grid[i][j] < 1 || grid[i][j] > 9 || (mask & (1 << grid[i][j])) > 0)return 0;
                mask = (mask | (1 << grid[i][j]));
                Row[i - m + 2] += grid[i][j];
            }
        }
        if(Row[0] != Row[1] || Row[0] != Row[2])return 0;
        // distinct
        for(int j = n - 2; j <= n; j++){
            int col_sum = 0;
            for(int i = m - 2; i <= m; i++){
                col_sum += grid[i][j];
            }
            if(col_sum != Row[0])return 0;
        }
        // two dia
        if(Row[0]  != grid[m - 2][n - 2] + grid[m - 1][n - 1] + grid[m][n])return 0;
        if(Row[0]  != grid[m][n - 2] + grid[m - 1][n - 1] + grid[m - 2][n])return 0;
        return 1;

    }   
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int ans = 0;
        int m = grid.size();
        int n = grid[0].size();
        for(int i = 2; i < m; i++){
            for(int j = 2; j < n; j++){
                ans += IsValid(i,j,grid);
            }
        }
        return ans;
    }
};