class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        int n = nums.size();
        while(k--){
            int idx = 0;
            for(int i = 0; i < n; i++)if(nums[idx] > nums[i])idx = i;
            nums[idx] *= multiplier;
        }
        return nums;
    }
};