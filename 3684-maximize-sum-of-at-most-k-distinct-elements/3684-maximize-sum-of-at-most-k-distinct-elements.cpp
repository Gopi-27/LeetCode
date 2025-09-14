class Solution {
public:
    vector<int> maxKDistinct(vector<int>& nums, int k) {
        vector<int>ans;
        sort(nums.begin(),nums.end(),greater<int>());
        int idx = 0;
        int n = nums.size();
        ans.push_back(nums[idx++]);
        k--;
        while(idx < n){
            if(k > 0 && ans[ans.size() - 1] != nums[idx]){
                ans.push_back(nums[idx++]);
                k--;
            }else idx++;  
        }
        return ans;
        
    }
};