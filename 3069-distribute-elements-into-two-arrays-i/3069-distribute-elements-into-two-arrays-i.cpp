class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n = nums.size();
        vector<int>Ans;
        Ans.push_back(nums[0]);
        int last = nums[1];
        nums[1] *= -1;
        for(int i = 2; i < n; i++){
            if(Ans.back() > last)Ans.push_back(nums[i]);
            else last = nums[i],nums[i] *= -1;
        }
        for(int i = 1; i < n; i++)
            if(nums[i] < 0)Ans.push_back(-nums[i]);
        return Ans;
    }
};

