class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int>rowmax(n);
        vector<int>colmax(n);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                colmax[j] = max(colmax[j],grid[i][j]);
                rowmax[i] = max(rowmax[i],grid[i][j]);
            }
        }
        int ans = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                ans += min(rowmax[i],colmax[j]) - grid[i][j];
            }
        }
        return ans;
    }
};