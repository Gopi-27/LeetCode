class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int n = nums.size();
        vector<bool>ans(n);
        long long mask = 0;
        for(int i = 0; i < n; i++){
            mask <<= 1;
            mask |= nums[i];
            mask %= 5;
            if(mask == 0)ans[i] = true;
        }
        return ans;
    }
};