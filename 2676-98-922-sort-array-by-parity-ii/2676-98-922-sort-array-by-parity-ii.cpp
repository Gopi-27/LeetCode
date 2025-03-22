class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int j = 0;
        while(i < n && j < n){
            while( i < n){
                if(nums[i] % 2 == 0)i++;
                else if(i % 2 == 1) i++;
                else break;
            }
            while( j < n){
                if(nums[j] % 2 == 1)j++;
                else if(j % 2 == 0)j++;
                else break;
            }
            if(i < n && j < n)swap(nums[i],nums[j]);
        }
        return nums;
    }
};