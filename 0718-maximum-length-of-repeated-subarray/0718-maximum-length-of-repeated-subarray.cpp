class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int maxi = 0;
        int n1 = nums1.size();
        int n2 = nums2.size();
        vector<vector<int>>Dp(n1 + 1,vector<int>(n2 + 1));
        for(int i = 0; i < n1; i++){
            for(int j = 0;  j < n2; j++){
                if(nums1[i] == nums2[j]){
                    Dp[i + 1][j + 1] = 1 + Dp[i][j];
                }
                maxi = max(maxi,Dp[i + 1][j + 1]);
            }
        }
        return maxi;
    }
};