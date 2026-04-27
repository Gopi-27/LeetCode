class Solution {
public:
    int mod = 1e9 + 7;
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
        int n = nums.size();
        vector<int>Denom(n + 1);
        for(vector<int>& r : requests){
            Denom[r[0]]++;
            Denom[r[1] + 1]--;
        }
        for(int i = 1; i < n; i ++)Denom[i] += Denom[i - 1];
        sort(Denom.begin(),Denom.end(),greater<int>());
        sort(nums.begin(),nums.end(),greater<int>());
        long long ans = 0;
        for(int i = 0; i < n; i++){
            ans = (ans + 1ll * nums[i] * Denom[i]) % mod;
        }
        return ans;
    }
};