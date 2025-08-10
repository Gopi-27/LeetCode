class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int m = grid.size();
        int n = grid[0].size();
        for(int i = 0; i < k; i++){
            int col = y + i;
            int l = x;
            int r = x + k - 1;
            while(l < r){
                swap(grid[l][col],grid[r][col]);
                l++;
                r--;
            }
        }
        return grid;
    }
};