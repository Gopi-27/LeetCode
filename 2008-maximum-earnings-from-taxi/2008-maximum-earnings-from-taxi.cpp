class Solution {
public:
    int GetNextRide(vector<vector<int>>& rides,int start){
        int key = rides[start][1];
        int low = start + 1;
        int high = rides.size() - 1;
        while(low <= high){
            int mid = (low + high) >> 1;
            if(rides[mid][0] < key)low = mid + 1;
            else high = mid - 1;
        }
        return low;
    }
    long long rec(int level,vector<vector<int>>& rides,vector<long long>& Dp){
        if(level >= rides.size())return 0;
        if(Dp[level] != -1)return Dp[level];
        long long  ans = rides[level][1] - rides[level][0] + rides[level][2] + rec(GetNextRide(rides,level),rides,Dp);
        ans = max(ans,rec(level + 1,rides,Dp));

        return Dp[level] = ans;
    }
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        sort(rides.begin(),rides.end());
        int m = rides.size();
        vector<long long>Dp(m,-1);
        return rec(0,rides,Dp);
    }
};