class Solution {
public:
    int rec(int i,int l,int r,int key,vector<int>& nums,vector<vector<vector<int>>>& Dp){
        if(l >= r)return 0;
        if(Dp[i][l][r] != -1)return Dp[i][l][r];
        int ans = 0;
        if(nums[l] + nums[l + 1] == key)ans = 1 + rec(i,l + 2,r,key,nums,Dp);
        if(nums[r] + nums[r - 1] == key)ans = max(ans,1 + rec(i,l,r - 2,key,nums,Dp));
        if(nums[l] + nums[r] == key)ans = max(ans,1 + rec(i,l + 1,r - 1,key,nums,Dp));
        return Dp[i][l][r] = ans;
    }
    int maxOperations(vector<int>& nums) {
        int n = nums.size();
        vector<vector<vector<int>>>Dp(3,vector<vector<int>>(n,vector<int>(n,-1)));
        int ans = 0;
        ans = max(ans,rec(0,0,n - 1,nums[0] + nums[1],nums,Dp));
        ans = max(ans,rec(1,0,n - 1,nums[n - 1] + nums[n - 2],nums,Dp));
        ans = max(ans,rec(2,0,n - 1,nums[0] + nums[n - 1],nums,Dp));
        return ans;        
    }
};