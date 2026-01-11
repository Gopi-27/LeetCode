class Solution {
public:
    int minDistance(string s1, string s2) {
        int m = s1.size();
        int n = s2.size();
        vector<vector<int>>Dp(n + 1,vector<int>(m + 1));
        // Dp[i][j] --> the minimum number of deletions required to make the string s1[0...j] and s2[0..i]
        // 0th row --> pref of s1
        // 0th col --> pref of s2
        for(int j = 1; j <= m; j++)Dp[0][j] = Dp[0][j - 1] + 1;

        for(int i = 1; i <= n; i++)Dp[i][0] = Dp[i - 1][0] + 1;

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                // s1[j - 1] 
                // s2[i - 1]
                if(s1[j - 1] == s2[i - 1]){
                    Dp[i][j] = Dp[i - 1][j - 1];
                }else{
                    Dp[i][j] = min(Dp[i - 1][j] + 1, Dp[i][j - 1] + 1);
                }
            }
        }
        return Dp[n][m];
    }
};