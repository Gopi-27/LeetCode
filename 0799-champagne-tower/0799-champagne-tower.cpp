class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>>Dp(query_row + 2,vector<double>(query_row + 2));
        Dp[0][0] = poured;
        for(int i = 0; i <= query_row; i++){
            for(int j = 0; j <= i; j++){
                if(Dp[i][j] <= 1)continue;
                double extra = (Dp[i][j] - 1)/2.0;
                Dp[i][j] = 1;
                Dp[i + 1][j] += extra;
                Dp[i + 1][j + 1] += extra;
            }
        }    
        return Dp[query_row][query_glass];
    }
};