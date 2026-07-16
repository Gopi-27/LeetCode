class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        long long ans = 0;
        int n = nums.size();
        vector<int>PrefGcd(n);
        PrefGcd[0] = nums[0];
        int maxi = nums[0];
        for(int i = 1; i < n; i++){
            maxi = max(maxi,nums[i]);
            PrefGcd[i] = gcd(maxi,nums[i]);
        }
        sort(PrefGcd.begin(),PrefGcd.end());
        for(int i = 0; i < n/2; i++){
            ans += gcd(PrefGcd[i],PrefGcd[n - i - 1]);
        }
        return ans;
    }
};