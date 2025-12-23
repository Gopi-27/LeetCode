class Solution {
public:
    int GetNextEvent(vector<vector<int>>& events,int last_idx){
        int key = events[last_idx][1]; // first event starts > key
        int low = last_idx + 1;
        int high = events.size() - 1;
        while(low <= high){
            int mid = (low + high) >> 1;
            if(events[mid][0] <= key)low = mid + 1;
            else high = mid - 1;
        }
        return low;
    }
    int rec(int level,int k, vector<vector<int>>& events,vector<vector<int>>& Dp){
        if(k == 0)return 0;
        if(level >= events.size())return 0;
        if(Dp[level][k] != -1)return Dp[level][k];
        // i got a valid event
        int ans = 0;
        // attend
        ans = events[level][2] + rec(GetNextEvent(events,level),k - 1,events,Dp);
        // not attend
        ans = max(ans,rec(level + 1,k,events,Dp));

        return Dp[level][k] = ans;

    }
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(),events.end());
        int n = events.size();
        vector<vector<int>>Dp(n,vector<int>(k + 1,-1));
        return rec(0,k,events,Dp);
    }
};