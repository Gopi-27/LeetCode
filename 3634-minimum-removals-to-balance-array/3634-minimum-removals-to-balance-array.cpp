class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int ans = n + 1;
        for(int i = 0; i < n; i++){
            int l = upper_bound(nums.begin(),nums.end(),1ll * k * nums[i]) - nums.begin();
            ans = min(ans, i + n - l);
        }
        return ans;
    }
};