class Solution {
public:
    int Ans(vector<int>& nums){
        int high = nums.size() - 1;
        int low = 0;
        while(low < high){
            int mid = (low + high) >> 1;
            
            if(mid % 2){
                if(nums[mid - 1] == nums[mid])low = mid + 1;
                else high = mid - 1;
            
            }else{
                if(nums[mid + 1] == nums[mid])low = mid;
                else high = mid;
               
            }
        }
        return nums[low];
    }
    int singleNonDuplicate(vector<int>& nums) {
        return Ans(nums);
    }
};