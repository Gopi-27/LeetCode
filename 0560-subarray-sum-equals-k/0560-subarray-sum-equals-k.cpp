class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans = 0;
        long long sum = 0;
        map<long long,int>mpp;
        mpp[0]++;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            sum += nums[i];
            if(mpp.count(sum - k))ans += mpp[sum - k];
            mpp[sum]++;
        }
        return ans;
    }
};