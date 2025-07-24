class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int area = 0;
        int n = grid.size();
        for(int i = 0; i < n; i++){
            int colmaxi = 0;
            int rowmaxi = 0;
            for(int j = 0; j < n; j++){
                colmaxi = max(grid[i][j],colmaxi);
                rowmaxi = max(grid[j][i],rowmaxi);
                if(grid[i][j] > 0)area++;
            }
            area += colmaxi + rowmaxi;
        }
        return area;
    }
};