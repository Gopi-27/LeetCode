class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int n = nums.size();
        cout << n;
        long long ans = 0;
        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] == 0)cnt++;
            else{
                ans += (1LL * cnt * (cnt + 1))/2;
                cnt = 0;
            }
        }
        ans += (1LL * cnt * (cnt + 1))/2;
        return ans; 
    }
};