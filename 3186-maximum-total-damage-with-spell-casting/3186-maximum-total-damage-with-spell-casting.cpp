class Solution {
public:
    int GetIdx(vector<pair<int,int>>& P,int key,int level){
        int low = level;
        int high = P.size() - 1;
        while(low <= high){
            int mid = (low + high) >> 1;
            if(P[mid].first >= key)high = mid - 1;
            else low = mid + 1;
        }
        return high + 1;
    }

    long long rec(int level,vector<pair<int,int>>& P,vector<long long >&Dp){

        if(level >= P.size())return 0;
        if(Dp[level] != -1)return Dp[level];
        // non - pick
        long long not_pick = rec(level + 1 ,P,Dp);
        // pick
        long long pick = 0;
        pick = (1LL * P[level].first * P[level].second) + rec(GetIdx(P,P[level].first + 3,level),P,Dp);

        return Dp[level] = max(not_pick,pick);

    }
    long long maximumTotalDamage(vector<int>& power) {
        map<int,int>mpp;
        for(auto b: power)mpp[b]++;
        vector<pair<int,int>>P;
        for(auto b : mpp)P.push_back({b.first,b.second});
        int n = P.size();
        vector<long long >Dp(n,-1);
        return rec(0,P,Dp);
    }
};