class Solution {
public:
    int rec(int l,int r,vector<int>& Pref,vector<vector<int>>& Dp){
        if(l == r)return 0;
        if(Dp[l][r] != -1)return Dp[l][r];
        int ans = 0;
        for(int i = l + 1; i <= r; i++){
            int left = Pref[i - 1] - ((l > 0)?Pref[l - 1]:0);
            int right = Pref[r] - Pref[i - 1];
            // cout << left << " -> " << right << endl;
            if(left > right)ans = max(ans,right + rec(i,r,Pref,Dp));
            else if(left < right)ans = max(ans,left + rec(l,i - 1,Pref,Dp));
            else ans = max(ans,max(left + rec(l,i - 1,Pref,Dp),right + rec(i,r,Pref,Dp)));
        }
        return Dp[l][r] = ans;
    }
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int>Pref(n);
        Pref[0] = stoneValue[0];
        for(int i = 1; i < n; i++)Pref[i] = Pref[i - 1] + stoneValue[i];
        vector<vector<int>>Dp(n + 1,vector<int>(n + 1,-1));
        return rec(0,n - 1,Pref,Dp);
    }
};