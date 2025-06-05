class Solution {
public:
    long long findTheArrayConcVal(vector<int>& nums) {
        long long ans = 0;
        int left = 0;
        int right = nums.size() - 1;
        while(left < right){
            int dig = log10(nums[right]) + 1;
            ans += nums[left] * pow(10,dig)  + nums[right];
            left++;
            right--;
        }
        if(left == right)ans += nums[left];
        return ans;
    }
};