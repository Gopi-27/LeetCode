class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int min =nums[0 + k - 1] - nums[0];
        for(int i = 1; i < (n - k + 1); i++){
            if(min > (nums[i + k - 1] - nums[i])){
                min = nums[i + k - 1] - nums[i];
            }
        }
        return min;
    }
};