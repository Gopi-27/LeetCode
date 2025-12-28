class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int j = n - 1;
        int i = 0;
        int ans = 0;
        while(i < m && j >= 0){
            while(i < m && grid[i][j] >= 0)i++;
            ans += m - i;
            j--;
        }
        return ans;
    }
};