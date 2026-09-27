class Solution {
public:
    int longestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        for(int i = 0; i < n; i++)nums[i] = nums[i] % k;
        int ans = 0;
        for(int i = 0; i < n; i++){
            map<int,int>mpp;
            long long sum = 0;
            for(int j = i; j < n; j++){
                sum += nums[j];
                mpp[((2 * nums[j]) % k + k) % k]++;
                if(sum % k == 0 || mpp.count((sum % k + k) % k))ans = max(ans,j - i + 1);
            }
        }
        return ans;
    }
};