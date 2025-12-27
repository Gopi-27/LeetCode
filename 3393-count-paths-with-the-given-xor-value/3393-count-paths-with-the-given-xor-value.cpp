class Solution {
public:
    int mod = 1e9 + 7;
    int countPathsWithXorValue(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<vector<int>>>Dp(m,vector<vector<int>>(n,vector<int>(32)));
        for(int i = m - 1; i >= 0; i--){
            for(int j = n - 1; j >= 0; j--){
                int val = grid[i][j];
                for(int x = 0; x < 32; x++){
                    if(i == m - 1 && j == n - 1){
                        if((val ^ x) == k)Dp[i][j][x] = 1;
                        else Dp[i][j][x] = 0;
                    }else{
                        int myxor = (x ^ val);
                        int down = 0;
                        int right = 0;
                        if(i + 1 < m)down = Dp[i + 1][j][myxor];
                        if(j + 1 < n)right = Dp[i][j + 1][myxor];
                        Dp[i][j][x] = (down + right) % mod;
                    }
                }
            }
        }
        
        return Dp[0][0][0];
    }
};