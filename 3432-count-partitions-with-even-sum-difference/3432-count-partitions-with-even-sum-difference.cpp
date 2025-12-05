class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int cnt = 0;
        int pref = 0;
        int suff = 0;
        for(int i = 0; i < nums.size(); i++)suff += nums[i];
        for(int i = 0; i < nums.size() - 1; i++){
            pref += nums[i];
            suff -= nums[i];
            if(abs(pref - suff) % 2 == 0)cnt++;
        }
        return cnt;
    }
};