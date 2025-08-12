class Solution {
public:
    int findMaxK(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int l = 0;
        int r = nums.size() - 1;
        while(l < r){
            while(l < r && nums[r] + nums[l] < 0)l++;
            if(nums[l] + nums[r] == 0)return nums[r];
            while(r > l && nums[l] + nums[r] > 0)r--;
        }
        return - 1;
    }
};