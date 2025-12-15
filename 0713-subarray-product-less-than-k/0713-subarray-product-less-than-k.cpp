class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k <= 1)return 0;
        int ans = 0;
        int n = nums.size();
        int i = 0;
        int j = 0;
        int cnt = 0;
        int pro = 1;
        while(i < n || j < n){
            while(i < n && pro * nums[i] < k){
                pro *= nums[i];
                i++;
                cnt++;
            }
            ans += cnt;
            if(j < n && j < i){
                pro /= nums[j++];
                cnt--;
            }
            if(i < n && i == j && nums[i] >= k){
                i++;
                j++;
            }
        }
        return ans;
    }
};