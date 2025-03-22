class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
     int n = nums.size();
     int i = 0;
     int j = 0;
     while(i < n && j < n){
        while(i < n && nums[i]%2 == 0)i++;
        while(j < n && nums[j]%2 == 1)j++;
        if(i > j) j++;
        else if (i < n && j < n){
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
        }

     }
     return nums;
    }
};