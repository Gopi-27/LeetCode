class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int,int>mpp;
        long long maxi = 0;
        long long sum = 0;
        int l = 0;
        int r = 0;
        int n = nums.size();
        while(r < n){
            while(r < n && !mpp[nums[r]]){
                mpp[nums[r]]++;
                sum += nums[r];
                maxi = max(maxi,sum);
                r++;
            }
            while(r < n && mpp[nums[r]]){
                mpp[nums[l]]--;
                sum -= nums[l];
                l++;
            }
        }
        return maxi;
    }
};