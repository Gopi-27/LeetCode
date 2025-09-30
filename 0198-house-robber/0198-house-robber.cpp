class Solution {
public:
    int rec(int level,vector<int>& nums){

        if(level < 0)return 0;

        // compute
        int ans = 0;
        // non-pick
        ans = max(ans,rec(level - 1,nums));
        // pick
        ans = max(ans,nums[level] + rec(level - 2,nums));

        return ans;
    }
    int rob(vector<int>& nums) {
        // if greedy fails then
        // Dp comes into picture
        int n = nums.size();
        return rec(n - 1,nums);
    }
};