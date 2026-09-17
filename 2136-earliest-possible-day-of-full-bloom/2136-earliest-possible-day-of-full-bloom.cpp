class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        int n = plantTime.size();
        vector<pair<int,int>>Pgrow(n);
        for(int i = 0; i < n; i++)Pgrow[i] = {growTime[i],plantTime[i]};
        sort(Pgrow.begin(),Pgrow.end(),greater<pair<int,int>>());
        int ans = 0;
        int day = 0;
        for(int i = 0; i < n; i++){
            int pT = Pgrow[i].second;
            int gT = Pgrow[i].first;
            day += pT;
            ans = max(ans,day + gT);
        }
        return ans;
    }
};