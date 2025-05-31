class Solution {
public:
    int returnToBoundaryCount(vector<int>& nums) {
       int x = 0;
       int n = nums.size();
       int cnt = 0;
       for(int i = 0; i < nums.size(); i++){
            x += nums[i];
            if(x == 0)cnt++;
       } 
       return cnt;
    }
};