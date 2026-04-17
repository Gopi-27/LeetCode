class Solution {
public:
    unordered_map<string,int>mpp;

    bool rec(int i,string upto,string&s,vector<vector<int>>&Dp){
        if(i >= s.size()){
            if(upto == "")return true;
            return mpp.count(upto);
        }
        upto += s[i];
        if(Dp[i][upto.size()] != -1)return Dp[i][upto.size()];
        bool ans = 0;        
        if(mpp.count(upto))ans |= rec(i + 1,"",s,Dp);
        if(ans)return ans;
        ans |= rec(i + 1,upto,s,Dp);
        return Dp[i][upto.size()] = ans;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        for(auto& str : wordDict)mpp[str]++;
        int n = s.size();
        vector<vector<int>>Dp(n,vector<int>(n + 1,-1));
        return rec(0,"",s,Dp);
    }
};