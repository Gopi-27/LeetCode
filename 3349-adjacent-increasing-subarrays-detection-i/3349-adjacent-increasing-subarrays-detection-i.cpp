class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        if(k == 1)return true;
        int n = nums.size();

        int cnt = 0;
        int prev_last = -2000;
        int cur_first = nums[0];
        int i = 1;
        while( i < n){
            int curlen = 1;
            while(curlen < k && i < n && nums[i - 1] < nums[i]){
                curlen++;
                i++;
            }
            if(curlen == k){
                prev_last = nums[i - 1];
                cnt++;
                if(cnt == 2)return true;
            }else{
                if(cnt & prev_last < cur_first){
                        prev_last = nums[i - 1];
                }else{
                    cnt = 0;
                }
            }
            cur_first = nums[i];
            i++;            
        }
        return false;
    }
};