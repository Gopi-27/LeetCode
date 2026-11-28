class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        sort(nums.begin(),nums.end(),greater<int>());
        int n = nums.size();
        int tot = 0; 
        for(int i = 0; i < n; i++)tot += nums[i];
        vector<int>Ans;
        int sum = 0;
        int i = 0;
        while(i < n && tot >= sum){
            Ans.push_back(nums[i]);
            sum += nums[i];
            tot -= nums[i];
            i++;
        }
        return Ans;
    }
};