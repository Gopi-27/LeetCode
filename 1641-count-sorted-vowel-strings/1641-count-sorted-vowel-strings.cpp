class Solution {
public:
    int rec(int level,int start,int n,vector<vector<int>>&Dp){
        // pruning
        
        // base case
        if(level > n)return 1;
        // cache
        if(Dp[level][start] != -1)return Dp[level][start];
        // compute
        int ans = 0;
        for(int i = start; i <= 5; i++){
            ans += rec(level + 1,i,n,Dp);
        }
        // save and return
        return Dp[level][start] = ans;     
    }
    int countVowelStrings(int n) {
        vector<vector<int>>Dp(n + 1,vector<int>(6,-1));
        return rec(1,1,n,Dp);
    }
};