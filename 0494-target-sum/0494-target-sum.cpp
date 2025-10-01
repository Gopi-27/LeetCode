class Solution {
public:
    int rec(int level,vector<int>&nums,int target){
        if(level == nums.size()){
            if(target == 0)return 1;
            return 0;
        }
        int ans = 0;
        // add 
        ans += rec(level + 1,nums,target - nums[level]);
        // sub
        ans += rec(level + 1,nums,target + nums[level]);
        
        return ans;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return rec(0,nums,target);
    }
};