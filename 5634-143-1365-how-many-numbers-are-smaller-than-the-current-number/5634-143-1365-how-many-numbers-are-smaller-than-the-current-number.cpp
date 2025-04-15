class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        map<int,int>mpp;
        for(auto b : nums)mpp[b]++;
        for(int i = 0; i < nums.size(); i++){
            int cnt = 0;
            for(auto b : mpp){
               if(b.first < nums[i])cnt += b.second;
               else break;
            }
            nums[i] = cnt;
        }
        return nums;
    }
};