class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        map<int,int>mpp;
        int pref = 0;
        int ans = 0;
        mpp[0] = -1;
        for(int i = 0; i < n; i++){
            if(nums[i])pref++;
            else pref--;

            if(mpp.count(pref))ans = max(ans,i - mpp[pref]);
            else mpp[pref] = i;
        }
        return ans;
    }
};