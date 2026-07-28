class Solution {
public:
    int Dp[101][101];
    bool rec(int i,int j,string& s1, string& s2, string& s){
        if(i + j >= s.size())return true;
        if(Dp[i][j] != -1)return Dp[i][j];
        bool flag = 0;
        if(i < s1.size() && s1[i] == s[i + j])flag |= rec(i + 1,j,s1,s2,s);
        if(j < s2.size() && s2[j] == s[i + j])flag |= rec(i,j + 1,s1,s2,s);
        return Dp[i][j] = flag;
    }
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size();
        int m = s2.size();
        if(n + m != s3.size())return false;
        memset(Dp,-1,sizeof(Dp));
        return rec(0,0,s1,s2,s3);
    }
};

// aabcc   

// dbbca


// aadbbcbcac