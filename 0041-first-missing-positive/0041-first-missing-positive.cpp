class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        nums.push_back(0);
        int n = nums.size();
        for(int i = 0; i < n; i++)if(nums[i] <= 0)nums[i] = n + 2;
        for(int i = 0; i < n; i++){
            int val = abs(nums[i]);
            if(val < n && nums[val] > 0)nums[val] = -nums[val];
        }
        for(int i = 1; i < n; i++)if(nums[i] > 0)return i;
        return n;
    }
};
