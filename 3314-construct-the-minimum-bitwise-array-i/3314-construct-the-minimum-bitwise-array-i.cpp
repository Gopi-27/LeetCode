class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(nums[i] % 2 == 0)nums[i] = -1;
            else{
                for(int a = nums[i]/2; a < nums[i]; a++){
                    if((a | (a + 1)) == nums[i]){
                        nums[i] = a;
                        break;
                    }
                    
                }
            }
        }
        return nums;
    }
};