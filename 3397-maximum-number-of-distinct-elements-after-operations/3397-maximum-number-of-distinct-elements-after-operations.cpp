class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int prev = nums[0] - k;
        int cnt = 1;
        int val = -k;
        for(int i = 1; i < n; i++){
            if(nums[i - 1] != nums[i])val = max(-k,prev - nums[i] + 1);
            if(nums[i] + val == prev && val < k)val++;
            if(nums[i] + val != prev)cnt++;
            prev = nums[i] + val;
        }
        return cnt;
    }
};