class Solution {
public:
    bool canMakeEqual(vector<int>& nums, int k) {
        vector<int>dummy = nums;
        int cnt1 = 0;
        int cnt_1 = 0;
        // to - 1 's;
        int n = nums.size();
        for(int i = 0; i < n - 1; i++){
            if(nums[i] == 1){
                nums[i] *= -1;
                nums[i + 1] *= -1;
                cnt_1++;
            }
        }
        if(nums[n - 1] == 1)cnt_1 = INT_MAX;
        // to 1 's;
        for(int i = 0; i < n - 1; i ++){
            if(dummy[i] == -1){
                dummy[i] *= -1;
                dummy[i + 1] *= -1;
                cnt1++;
            }
        }
        if(dummy[n - 1] == -1)cnt1 = INT_MAX;
        int req_oper = min(cnt1,cnt_1);
        if(req_oper <= k)return true;
        return false;
        
    }
};