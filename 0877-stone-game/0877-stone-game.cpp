class Solution {
public:
    pair<int,int> rec(int l,int r,vector<int>& piles,vector<vector<pair<int,int>>>&Dp){
        if(l > r)return {0,0};
        if(Dp[l][r].first != -1)return Dp[l][r];
        pair<int,int>s1 = rec(l + 1,r,piles,Dp);
        pair<int,int>s2 = rec(l,r - 1,piles,Dp);

        pair<int,int> ans;
        if(piles[l] + s1.second > piles[r] + s2.second)ans = {piles[l] + s1.second,s1.first};
        else ans = {piles[r] + s2.second,s2.first};

        return Dp[l][r] = ans;
    }
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<pair<int,int>>>Dp(n + 1,vector<pair<int,int>>(n + 1,{-1,-1}));
        pair<int,int>ans = rec(0,n - 1,piles,Dp);
        return ans.first > ans.second;
    }
};