class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        int n = grid.size();
        for(int i = 0; i < n; i++){
            sort(grid[i].begin(),grid[i].end());
        }
        int ans = 0;
        int m = grid[0].size();
        for(int j = 0; j < m; j++){
            int max = grid[0][j];
            for(int i = 1; i < n; i++){
                if(max < grid[i][j])max = grid[i][j];
            }
            ans += max;
        }
        return ans;
    }
};