class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n = landStartTime.size();
        int m = waterStartTime.size();
        vector<int>L(n),W(m);
        for(int i = 0; i < n; i++)L[i] = landStartTime[i] + landDuration[i];
        for(int i = 0; i < m; i++)W[i] = waterStartTime[i] + waterDuration[i];
        sort(L.begin(),L.end());
        sort(W.begin(),W.end());
        // L -> W
        int e = L[0];
        int ans = INT_MAX;
        for(int i = 0; i < m; i++){
            if(waterStartTime[i] <= e)ans = min(ans,e + waterDuration[i]);
            else ans = min(ans,waterStartTime[i] + waterDuration[i]);
        }
        e = W[0];
        for(int i = 0; i < n; i++){
            if(landStartTime[i] <= e)ans = min(ans, e + landDuration[i]);
            else ans = min(ans,landStartTime[i] + landDuration[i]);
        }
        return ans;
    }
};
