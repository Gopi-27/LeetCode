class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int left = 0;
        int right = left + 1;
        int cnt = 0;
        while(left < n){
            
            
            while(right < n &&  nums[right] - nums[left] <= k){
                while(right < n - 1 && nums[right + 1] == nums[right])right++;
                if( nums[right] - nums[left] == k)cnt++;
                right++;
            }
            while(left < n - 1 && nums[left + 1] == nums[left])left++;
            left ++;
            right = left + 1;
        }
    return cnt;
    }
};