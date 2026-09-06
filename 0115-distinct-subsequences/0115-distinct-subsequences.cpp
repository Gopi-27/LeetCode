class Solution {
public:
    int Dp[1001][1001];
    int rec(int i,int j,string& s,string& t){
        if(j >= t.size())return 1;
        if(i >= s.size())return 0;
        if(Dp[i][j] != -1)return Dp[i][j];
        int ans = rec(i + 1,j,s,t);
        if(s[i] == t[j])ans += rec(i + 1,j + 1,s,t);
        return Dp[i][j] = ans;
    }
    int numDistinct(string s, string t) {
        memset(Dp,-1,sizeof(Dp));
        return rec(0,0,s,t);
    }
};