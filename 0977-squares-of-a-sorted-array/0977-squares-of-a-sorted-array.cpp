class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int>Ans(n);
        int idx = n - 1;
        int l = 0;
        int r = n - 1;
        while(l <= r){
            if(abs(nums[l]) >= abs(nums[r]))Ans[idx--] = nums[l] * nums[l++];
            else Ans[idx--] = nums[r] * nums[r--];
        }
        return Ans;

    }
};