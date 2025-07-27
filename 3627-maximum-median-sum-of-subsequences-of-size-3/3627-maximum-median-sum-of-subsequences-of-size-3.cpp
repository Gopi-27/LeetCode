class Solution {
public:
    long long maximumMedianSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int quo = n / 3;
        int i = n - 2;
        long long sum = 0;
        while(quo--){
            sum += nums[i];
            i -= 2;
        }
        return sum;
    }
};