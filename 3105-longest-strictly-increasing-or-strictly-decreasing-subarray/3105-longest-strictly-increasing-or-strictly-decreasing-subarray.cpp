class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        vector<int>diff;
        for(int i = 1; i < n; i++){
            diff.push_back(nums[i - 1] - nums[i] > 0 ? 0 : nums[i - 1] - nums[i] < 0 ? 1 : 2);
        }
        int i = 0;
        n--;
        while(i < n){
            while(i < n && diff[i] == 2)i++;
            int s = i;
            while(i < n && diff[i] == 1)i++;
            ans = max(ans,i - s);
            s = i;
            while(i < n && diff[i] == 0)i++;
            ans = max(ans,i - s);
        }
        return ans + 1;
    }

};