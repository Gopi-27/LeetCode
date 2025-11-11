class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        // Space Optimization
        vector<int>prev(m);
        for(int i = 0; i < n; i++){
            vector<int>curr(m);
            for(int j = 0; j < m; j++){
                if(i == 0 && j == 0)curr[j] = grid[i][j];
                else{
                    int mini = INT_MAX;
                    if(i > 0)mini = min(mini,prev[j]);
                    if(j > 0)mini = min(mini,curr[j - 1]);
                    curr[j] = mini + grid[i][j];
                }
            }
            prev = curr;
        }
        return prev[m - 1];
    }
};