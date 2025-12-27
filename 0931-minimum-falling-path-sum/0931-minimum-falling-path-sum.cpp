class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>>Dp(n,vector<int>(n));
        for(int i = n - 1; i >= 0; i--){
            for(int j = 0; j < n; j++){
                if(i == n - 1)Dp[i][j] = matrix[i][j];
                else{
                    int mini = matrix[i][j] + Dp[i + 1][j];
                    if(j - 1 >= 0)mini = min(mini,matrix[i][j] + Dp[i + 1][j - 1]);
                    if(j + 1 < n)mini = min(mini,matrix[i][j] + Dp[i + 1][j + 1]);
                    Dp[i][j] = mini;
                }
            }
        }
        int mini = INT_MAX;
        for(int j = 0; j < n; j++)mini = min(mini,Dp[0][j]);
        return mini;
    }
};
