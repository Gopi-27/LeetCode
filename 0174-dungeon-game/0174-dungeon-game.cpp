class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size();
        int n = dungeon[0].size();
        vector<vector<int>>Dp(m,vector<int>(n));
        Dp[m - 1][n - 1] = (dungeon[m - 1][n - 1] > 0)? 0: abs(dungeon[m - 1][n - 1]) + 1;
        for(int i = m - 1; i >= 0; i--){
            for(int j = n - 1; j >= 0; j--){
                if(i == m - 1 && j == n - 1)continue;
                int req_right = 1e9;if(j + 1 < n)req_right = Dp[i][j + 1];
                int req_down = 1e9;if(i + 1 < m)req_down = Dp[i + 1][j];

                if(dungeon[i][j] > 0){
                    if(dungeon[i][j] >= req_right)Dp[i][j] = 0;
                    else Dp[i][j] = req_right - dungeon[i][j];

                    if(dungeon[i][j] >= req_down)Dp[i][j] = 0;
                    else Dp[i][j] = min(Dp[i][j],req_down - dungeon[i][j]);
                }else{
                    int extra = -dungeon[i][j];
                    int r_ans = (req_right > 0)?req_right:1;
                    int d_ans = (req_down > 0)?req_down:1;
                    Dp[i][j] = extra + min(r_ans,d_ans);
                }
                                    
            }
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                cout << Dp[i][j] << " ";
            }
            cout << endl;
        }
        return (Dp[0][0] == 0)? 1 :Dp[0][0];
    }
};