class Solution {
public:
    unordered_map<int,vector<int>>mpp;
    unordered_map<int,int>ptr;
    Solution(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++)mpp[nums[i]].push_back(i);
        for(auto& b : mpp)ptr[b.first] = 0;
    }
    
    int pick(int target) {
        int idx = ptr[target];
        ptr[target] = (ptr[target] + 1) % mpp[target].size();
        return mpp[target][idx];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */