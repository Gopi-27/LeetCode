class Solution {
public:
    vector<int> findColumnWidth(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int>ans(m);
        for(int j = 0; j < m; j++){
            int maxi = 0;
            for(int i = 0; i < n; i++){
                int l = 1;
                if(grid[i][j] > 0)l += log10(grid[i][j]);
                else if(grid[i][j] < 0)l += log10(-grid[i][j]) + 1;
                maxi = max(maxi,l);
                cout << maxi;
            }
            ans[j] = maxi;
        }
        return ans;
    }
};