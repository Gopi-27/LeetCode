class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans = 0;
        int n = nums.size();
        for(int i = 1; i < n; i++){
            if(nums[i] == nums[i - 1])ans ^= nums[i];
        }
        return ans;

    }
};