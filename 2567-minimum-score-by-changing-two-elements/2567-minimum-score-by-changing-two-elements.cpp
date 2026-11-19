class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        return min({nums[n - 1] - nums[2],nums[n - 3] - nums[0], nums[n - 2] - nums[1]});
    }
};

// [59,27,9,81,33]
// 9 27 33 59 81
// 81
// 33
// [58,42,8,75,28]
// 8 28 42 58 75