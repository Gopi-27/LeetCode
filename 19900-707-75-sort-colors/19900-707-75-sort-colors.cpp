class Solution {
public:
    void sortColors(vector<int>& nums) {
        int frontidx = 0;
        int backidx = nums.size() - 1;
        int curidx = 0;
        while(curidx <= backidx){
            if(nums[curidx] == 0){
                int temp = nums[frontidx];
                nums[frontidx++] = 0;
                nums[curidx++] = temp;
            }else if(nums[curidx] == 2){
                int temp = nums[backidx];
                nums[backidx--] = 2;
                nums[curidx] = temp;
            }else{
                curidx++;
            }
        }
        return ;
    }
};