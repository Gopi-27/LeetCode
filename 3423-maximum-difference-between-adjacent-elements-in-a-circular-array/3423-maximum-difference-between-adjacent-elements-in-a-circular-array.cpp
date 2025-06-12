class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int dif = abs(nums[0] - nums[1]);
        int max = dif;
        int n = nums.size();
        for(int i = 1; i < n - 1; i++){
            dif = abs(nums[i] - nums[i + 1]);
            if(max < dif)max = dif;
        }
        dif = abs(nums[n - 1] - nums[0]);
        if(max < dif)max = dif;
        return max;


    }
};