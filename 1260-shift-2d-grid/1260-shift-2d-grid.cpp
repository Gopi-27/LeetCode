class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        vector<int>T;
        int n = grid.size();
        int m = grid[0].size();
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                T.push_back(grid[i][j]);
        int l = T.size();
        vector<int>Ans(l);
        for(int i = 0; i < l; i++)
            Ans[(i + k) % l] = T[i];
        int p = 0;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                grid[i][j] = Ans[p++];
        return grid;
    }
};