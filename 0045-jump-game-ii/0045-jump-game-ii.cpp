class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)return 0;
        vector<int>Dp(n);
        Dp[n - 1] = 0;
        for(int i = n - 2; i >= 0; i--){
            int mini = 1e9;
            int steps = nums[i];
            for(int j = 1; j <= steps; j++){
                if(i + j >= n)break;
                mini = min(mini,Dp[i + j]);
            }
            Dp[i] = mini + 1;
        }
        return Dp[0];
    }
};
// dp[i] minimum no.of steps required to reach n - 1
// 