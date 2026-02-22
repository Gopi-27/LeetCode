class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int>OnesRow(n);
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                OnesRow[i] += grid[i][j];
        vector<int>OnesCol(m);
        for(int j = 0; j < m; j++)
            for(int i = 0; i < n; i++)
                OnesCol[j] += grid[i][j];
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                grid[i][j] = 2 * (OnesRow[i] + OnesCol[j]) - (m  + n);
        return grid; 
    }
};