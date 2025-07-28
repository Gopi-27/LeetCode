class Solution {
public:
    int minMoves(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int cnt = 0;
        int n = nums.size();
        for(int i = 1; i < n; i++){
            nums[i] += cnt;
            cnt += nums[i] - nums[i - 1]; 
        }
        return cnt;

    }
};