class Solution {
public:
    int mod = 1e9 + 7;
    int rec(int level,int target,int k,int n,vector<vector<int>>& Dp){
        if(target < 0)return 0;
        if(level == n + 1){
            if(target == 0)return 1;
            return 0;
        }
        if(Dp[level][target] != -1)return Dp[level][target];
        long long ans = 0;
        for(int i = 1; i <= k; i++){
            ans += rec(level + 1,target - i,k,n,Dp);
            ans %= mod;
        }
        return Dp[level][target] = ans;
    }
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>>Dp(n + 2,vector<int>(target + 1,-1));
        return rec(1,target,k,n,Dp);
    }
};