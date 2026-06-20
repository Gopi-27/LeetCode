class Solution {
public:
    bool rec(int i,int sum,vector<int>& nums,int tot,vector<vector<int>>& Dp){
        if(i >= nums.size()){
            if(tot - sum == sum)return 1;
            return 0;
        }
        if(Dp[i][sum] != -1)return Dp[i][sum];
        return Dp[i][sum] = rec(i + 1,sum,nums,tot,Dp) | rec(i + 1,sum + nums[i],nums,tot,Dp);
    }
    bool canPartition(vector<int>& nums) {
        int tot = 0;
        for(int& v : nums)tot += v;
        vector<vector<int>>Dp(nums.size(),vector<int>(tot + 1,-1));
        return rec(0,0,nums,tot,Dp);
    }
};