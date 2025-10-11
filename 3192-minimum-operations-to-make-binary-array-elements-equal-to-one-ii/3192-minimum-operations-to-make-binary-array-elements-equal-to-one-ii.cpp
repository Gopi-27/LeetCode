class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int flips = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] == 0){
                if(flips % 2 == 0)flips++;
            }else{
                if(flips % 2 == 1)flips++;
            }
        }
        return flips;
    }
};