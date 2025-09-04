class Solution {
public:
    int rec(int level,vector<int>&A,int n,vector<int>& Dp){
        // pruning
        
        //basecase
        if(level >= n)return 0;
        if(Dp[level] != -1)return Dp[level];        
        //compute
        int ans = 0;

        // one step
        ans = A[level] + rec(level + 1,A,n,Dp);
        // two step
        ans = min(A[level] + rec(level + 2,A,n,Dp),ans);
        //save / return;
        return Dp[level] = ans;
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int>Dp(n,-1);
        return min(rec(1,cost,n,Dp),rec(0,cost,n,Dp));
    }
};