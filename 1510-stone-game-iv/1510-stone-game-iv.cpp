class Solution {
public:
    bool rec(int n,vector<int>& Dp){
        if(n <= 0)return false;
        if(Dp[n] != -1)return Dp[n];
        bool flag = 1;
        for(int i = 1; i * i <= n; i++){
            flag &= rec(n - i * i,Dp);
        }
        return Dp[n] = !flag;
    }
    bool winnerSquareGame(int n) {
        vector<int>Dp(n + 1,-1);
        return rec(n,Dp);
    }
};