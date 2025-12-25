class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MIN;
        int curr_window = 0;
        for(int i = 0; i < n; i++){
            curr_window += nums[i];
            curr_window = max(curr_window,nums[i]);
            ans = max(ans,curr_window);
        }
        return ans;
    }
};