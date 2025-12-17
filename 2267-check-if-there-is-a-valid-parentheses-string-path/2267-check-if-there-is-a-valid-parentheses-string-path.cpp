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
        vector<vector<vector<int>>>Dp(m,vector<vector<int>>(n,vector<int>(m + n, -1)));
        return rec(0,0,0,grid,Dp);
    }
};
// ["(","(","("]
// [")","(",")"]
// ["(","(",")"]
// ["(","(",")"]