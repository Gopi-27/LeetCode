class Solution {
public:
    int mod = 1e9 + 7;
    int sumDistance(vector<int>& nums, string s, int d) {
        int n = nums.size();
        vector<long long>Final(n);
        for(int i = 0; i < n; i++){
            if(s[i] == 'R')Final[i] = 0ll + nums[i] + d;
            else Final[i] = 0ll + nums[i] - d;
        }
        sort(Final.begin(),Final.end());
        long long ans = 0;
        long long prev = 0;
        for(int i = 0; i < n - 1; i++){
            prev = (prev - i + mod) % mod;
            prev += n - i - 1;
            prev %= mod;
            ans = (ans + (prev * (Final[i + 1] - Final[i]) % mod) % mod) % mod;
        }
        return ans;
    }
};
 
