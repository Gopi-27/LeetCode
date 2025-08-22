class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int left = INT_MAX;
        int right = INT_MIN;
        int top = left;
        int bottom = right;

        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j]){
                    left = min(left,j);
                    right = max(right,j);

                    top = min(top,i);
                    bottom = max(bottom,i);

                }
            }
        }

        return (right - left + 1) * (bottom - top + 1);




    }
};