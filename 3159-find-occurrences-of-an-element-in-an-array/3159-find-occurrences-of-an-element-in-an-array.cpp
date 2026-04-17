class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        vector<int>Xidx;
        int n = nums.size();
        for(int i = 0; i < n; i++)if(nums[i] == x)Xidx.push_back(i);
        vector<int>ans;
        for(int &q: queries)
            ans.push_back((q <= Xidx.size()) ? Xidx[q - 1] : -1);
        return ans;          
    }
};