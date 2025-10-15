class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int cur = 1;
        int prev = 0;
        int ans = 0;
        int n = nums.size();
        for(int i = 1; i < n; i++){
            if(nums[i - 1] < nums[i]){
                cur++;
            }else{
                prev = cur;
                cur = 1;
            }
            ans = max(ans,max(cur/2,min(prev,cur)));
        }
        return ans;
    }
};