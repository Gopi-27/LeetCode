class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        // space optimization
        vector<int>prev(m);
        prev[0] = 1;
        for(int i = 0; i < n; i++){
            vector<int>curr(m);
            for(int j = 0; j < m; j++){
                if(obstacleGrid[i][j])curr[j] = 0;
                else{
                    curr[j] = prev[j];
                    if(j > 0)curr[j] += curr[j - 1];; 
                }
            }
            prev = curr;
        }
        return prev[m - 1];
    }
};