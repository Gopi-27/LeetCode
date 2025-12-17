class Solution {
public:
    bool rec(int i, int j,int open,vector<vector<char>>& grid,vector<vector<vector<int>>>& Dp){
        if(i == grid.size() - 1 && j == grid[0].size()){
            if(!open)return true;
            return false;
        }
        if(i >= grid.size() || j >= grid[0].size())return false;
        if(Dp[i][j][open] != -1)return Dp[i][j][open];
        bool flag = 0;
        if(grid[i][j] == '('){
            flag = rec(i,j + 1,open + 1,grid,Dp);
            flag |= rec(i + 1,j,open + 1,grid,Dp);
        }else{
            // close
            if(open){
                flag = rec(i,j + 1,open - 1,grid,Dp);
                flag |= rec(i + 1, j,open - 1,grid,Dp);
            }
        }
        return Dp[i][j][open] = flag;

    }
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        if(grid[m - 1][n - 1] == '(')return false;
        // vector<vector<vector<int>>>Dp(m,vector<vector<int>>(n,vector<int>(m + n, -1)));
        vector<vector<vector<bool>>>Dp(m,vector<vector<bool>>(n,vector<bool>(m + n + 1,false)));
        // Tabulation
        
        for(int i = m - 1; i >= 0; i--){
            for(int j = n - 1; j >= 0; j--){
                for(int open = 0; open < m + n; open++){
                    if(i == m - 1 && j == n - 1 && open == 1){
                        Dp[m - 1][n - 1][1] = true;
                        continue;
                    }
                    bool flag = 0;
                    if(grid[i][j] == '('){
                        if(j + 1 < n)flag = Dp[i][j + 1][open + 1];
                        if(i + 1 < m)flag |= Dp[i + 1][j][open + 1];
                    }else{
                        // close
                        if(open){
                            if(j + 1 < n)flag = Dp[i][j + 1][open - 1];
                            if(i + 1 < m)flag |= Dp[i + 1][j][open - 1];
                        }
                    }
                    Dp[i][j][open] = flag;
                }
            }
        }
        return Dp[0][0][0];
    }
};
// ["(","(","("]
// [")","(",")"]
// ["(","(",")"]
// ["(","(",")"]