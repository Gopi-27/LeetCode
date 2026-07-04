class Solution {
public:
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<long long>Pref(n);
        Pref[0] = nums[0];
        for(int i = 1; i < n; i++)Pref[i] = nums[i] + Pref[i - 1];
        vector<long long>Ans;
        for(int &q : queries){
            long long idx = lower_bound(nums.begin(),nums.end(),q) - nums.begin();
            long long lsum = (idx > 0) ? Pref[idx - 1]: 0;
            Ans.push_back((idx * q - lsum) + (Pref[n - 1] - lsum) - ((n - idx) * q));
        }
        return Ans;
    }
};