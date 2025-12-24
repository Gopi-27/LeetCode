class Solution {
public:
    int GetNextJob(vector<vector<int>>& Jobs,int start){
        int key = Jobs[start][1];
        int low = start + 1;
        int high = Jobs.size() - 1;
        while(low <= high){
            int mid = (low + high) >> 1;
            if(Jobs[mid][0] < key)low = mid + 1;
            else high = mid - 1;
        }
        return low;
    }
    int rec(int level,vector<vector<int>>& Jobs,vector<int>& Dp){
        if(level >= Jobs.size())return 0;
        if(Dp[level] != -1)return Dp[level];
        int ans = Jobs[level][2] + rec(GetNextJob(Jobs,level),Jobs,Dp);
        ans = max(ans,rec(level + 1,Jobs,Dp));
        return Dp[level] = ans;
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<vector<int>>Jobs(n,vector<int>(3));
        for(int i = 0; i < n; i++){
            Jobs[i][0] = startTime[i];
            Jobs[i][1] = endTime[i];
            Jobs[i][2] = profit[i];
        }
        sort(Jobs.begin(),Jobs.end());
        vector<int>Dp(n,-1);
        return rec(0,Jobs,Dp);
    }
};