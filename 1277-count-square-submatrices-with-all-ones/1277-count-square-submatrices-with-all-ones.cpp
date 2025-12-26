class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>>Dp(m,vector<int>(n));
        for(int i = m - 1; i >=0; i--){
            for(int j = n - 1; j >=0; j--){
                if(matrix[i][j] == 0){
                    Dp[i][j] = 0;
                    continue;
                }

                int right = 0;
                int down = 0;
                int corner = 0;

                if(j + 1 < n)right = Dp[i][j + 1];
                if(i + 1 < m)down = Dp[i + 1][j];
                if(i + 1 < m && j + 1 < n)corner = Dp[i + 1][j + 1];

                Dp[i][j] = 1 + min({right,down,corner});
            }
        }
        int ans = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                ans += Dp[i][j];
            }
        }
        return ans;
    }
};