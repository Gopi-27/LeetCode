class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maxiBit) {
        int mask = 0;
        while(maxiBit--){
            mask = (mask << 1) | 1;
        }
        int n = nums.size();
        vector<int>ans(n);
        for(int i = 1; i < n; i++){
            nums[i] ^= nums[i - 1];
        }
        for(int i = n - 1; i >= 0; i--){
            ans[n - i - 1] = nums[i] ^ mask;
        }
        return ans;
    }
};