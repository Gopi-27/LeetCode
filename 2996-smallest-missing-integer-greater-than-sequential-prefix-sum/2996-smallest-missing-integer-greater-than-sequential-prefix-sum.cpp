class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();
        int ans = nums[0];
        for(int i = 1; i < n; i++){
            if(nums[i - 1] + 1 == nums[i])ans += nums[i];
            else break;
        }
        cout << ans ;
        sort(nums.begin(),nums.end());
        int idx = lower_bound(nums.begin(),nums.end(),ans) - nums.begin();
        if(idx == n || nums[idx] != ans)return ans;
        for(int i = idx; i < n; i++){
            if(nums[i] < ans)continue;
            if(nums[i] != ans)return ans;
            ans++;
        }
        return ans;
    }
};