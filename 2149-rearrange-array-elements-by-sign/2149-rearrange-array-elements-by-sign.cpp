class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int j = 0;
        vector<int>Ans;
        while(i < n && j < n){
            while(i < n && nums[i] < 0)i++;// first postive
            while(j < n && nums[j] > 0)j++;// first negative
            Ans.push_back(nums[i++]);
            Ans.push_back(nums[j++]);
        }
        return Ans;
    }
};