class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int maxi = INT_MIN;
        vector<vector<int>>Dp(n + 1,vector<int>(m + 1));
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                int val = nums1[i - 1] * nums2[j - 1];
                Dp[i][j] = max(val,val + Dp[i - 1][j - 1]);
                if(j > 1)Dp[i][j] = max(Dp[i][j],Dp[i][j - 1]);
                if(i > 1)Dp[i][j] = max(Dp[i][j],Dp[i - 1][j]);
                // cout << Dp[i][j] << " ";
                maxi = max(maxi,Dp[i][j]);
            }
            // cout << "\n";
        }
        
        return maxi;
    }
};