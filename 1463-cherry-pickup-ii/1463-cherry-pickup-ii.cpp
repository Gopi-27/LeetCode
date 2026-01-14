class Solution {
public:
    int GetCherry(vector<vector<vector<int>>> &Dp,int i,int a,int b){
        if(i >= Dp.size())return 0;
        if(a < 0 || a >= Dp[0].size() || b < 0 || b >= Dp[0].size())return 0;
        return Dp[i][a][b];
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>>Dp(n,vector<vector<int>>(m,vector<int>(m)));
        for(int i = n - 1; i >= 0; i--){
            for(int a = 0; a < m; a++){
                for(int b = 0; b < m; b++){
                    int val = 0;
                    if(a == b)val = grid[i][a];
                    else val = grid[i][a] + grid[i][b];
                    int cherry = 0;
                    for(int ra = -1; ra <= 1; ra++){
                        for(int rb = -1; rb <= 1; rb++){
                           cherry = max(cherry,GetCherry(Dp,i + 1,a + ra,b + rb));
                        }
                    }
                    Dp[i][a][b] = cherry + val;
                }
            }
        }
        return Dp[0][0][m - 1];
    }
};