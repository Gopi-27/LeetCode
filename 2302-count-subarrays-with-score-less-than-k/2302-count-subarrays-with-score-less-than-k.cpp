class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long ans = 0;
        int cnt = 0;
        long long sum = 0;
        int left = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            cnt++;
            while((sum * (cnt)) >= k){
                cnt--;
                sum -= nums[left];
                left++;
            }
            ans += cnt;
        }
        return ans;
    }
};