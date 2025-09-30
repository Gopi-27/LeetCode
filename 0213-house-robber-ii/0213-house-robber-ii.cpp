class Solution {
public:
    int rec(int level,vector<int>& nums,vector<int>&Dp){
        if(level < 0)return 0;
        if(Dp[level] != -1)return Dp[level];
        int ans = 0;
        ans = max(ans,rec(level - 1,nums,Dp));
        ans = max(ans,nums[level] + rec(level - 2,nums,Dp));
        return Dp[level] = ans;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)return nums[0];

        vector<int>dummy1(nums.begin() + 1,nums.end());
        vector<int>dummy2(nums.begin(),nums.end() - 1);
        vector<int>Dp(n,-1);
        int ans = rec(n - 2,dummy1,Dp);
        fill(Dp.begin(),Dp.end(),-1);
        ans = max(ans,rec(n - 2,dummy2,Dp));
        return ans;
        
       
    }
};