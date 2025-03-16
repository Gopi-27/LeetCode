class Solution {
public:
    int maxSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        map<int,int>mpp;
        for(int b : nums)mpp[b]++;
        int sum = 0;
        for(auto b : mpp){
            if(b.first > 0)sum += b.first;
        }
        if(sum == 0)return nums[n-1];
        else return sum;
    }
};