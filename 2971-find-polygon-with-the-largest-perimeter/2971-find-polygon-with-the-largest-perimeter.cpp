class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<long long>Pref(n);
        Pref[0] = nums[0];
        for(int i = 1; i < n; i++)Pref[i] = Pref[i - 1] + nums[i];
        for(int i = n - 1; i >= 2; i--)if(Pref[i - 1] > nums[i])return Pref[i];
        return - 1;
    }
};