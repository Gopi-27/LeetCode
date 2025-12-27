class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        for(int i = n - 2; i >= 0; i--){
            for(int j = 0; j < n; j++){
                int mini = INT_MAX;
                for(int k = 0; k < n; k++){
                    if(k == j)continue;
                    mini = min(mini,grid[i][j] + grid[i + 1][k]);
                }
                grid[i][j] = mini;
            }
        }
        int mini = INT_MAX;
        for(int j = 0; j < n; j++)mini = min(mini,grid[0][j]);
        return mini;
    }
};