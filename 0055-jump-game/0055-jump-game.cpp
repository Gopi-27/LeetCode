class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums[0] == 0 && nums.size() == 1)return true; 
        int maxi = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            maxi = max(maxi,i + nums[i]);
            if(nums[i] == 0){
                if(maxi <= i)return false;
            }
        }
        return true;
    }
};