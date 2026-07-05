class Solution {
public:
    int mod = 1e9 + 7;
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();
        vector<vector<vector<int>>>Dp(n,vector<vector<int>>(n,vector<int>(2)));
        board[n - 1][n - 1] = '0';
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i == 0 && j == 0){
                    Dp[i][j][0] = 0;
                    Dp[i][j][1] = 1;
                    continue;
                }
                if(board[i][j] == 'X'){
                    Dp[i][j][0] = 0;
                    Dp[i][j][1] = 0;
                    continue;
                }   

                int upsum = (i > 0)? Dp[i - 1][j][0]:0; upsum += board[i][j] - '0';
                int uppaths = (i > 0)? Dp[i - 1][j][1]:0;

                int lsum = (j > 0)? Dp[i][j - 1][0]:0; lsum += board[i][j] - '0';
                int lpaths = (j > 0)? Dp[i][j - 1][1]:0;

                int csum = (i > 0 && j > 0)? Dp[i - 1][j - 1][0]:0; csum += board[i][j] - '0';
                int cpaths = (i > 0 && j > 0)? Dp[i - 1][j - 1][1]:0;

                vector<pair<int,int>>T = {{upsum,uppaths},{lsum,lpaths},{csum,cpaths}};
                sort(T.begin(),T.end(),greater<pair<int,int>>());
                Dp[i][j][0] = T[0].first;
                for(pair<int,int>& p : T){
                    if(p.first == T[0].first){
                        Dp[i][j][1] = (Dp[i][j][1] + p.second) % mod;
                    }
                }
            }
        }
        if(Dp[n - 1][n - 1][1] == 0)return {0,0};
        return Dp[n - 1][n - 1];
    }
};