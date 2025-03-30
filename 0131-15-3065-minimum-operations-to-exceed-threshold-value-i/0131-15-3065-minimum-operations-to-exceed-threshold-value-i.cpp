class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int low = 0;
        int high = n - 1;
        while(low <= high){
            int mid = (low + high) >> 1;
            if(nums[mid] >= k)high = mid - 1;
            else low = mid + 1;
        }
        return high + 1;
    }
};