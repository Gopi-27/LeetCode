class Solution {
public:
    int Tri(int level,vector<int>& Dp){
        if(Dp[level] != -1)return Dp[level];
        Dp[level] = Tri(level - 1,Dp) + Tri(level - 2,Dp) + Tri(level - 3,Dp);
        return Dp[level];
    }
    int tribonacci(int n) {
        if(n == 0)return 0;
        if(n == 1 || n == 2)return 1;
        vector<int>Dp(n + 1,-1);
        Dp[0] = 0;
        Dp[1] = 1;
        Dp[2] = 1;
        return Tri(n,Dp);
    }
};