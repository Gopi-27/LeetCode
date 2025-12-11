class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        n++;
        vector<pair<int,int>>LR(n,{n,-1});
        vector<pair<int,int>>DU(n,{n,-1});
        for(auto b : buildings){
            int x = b[0];
            int y = b[1];
            LR[y].first = min(LR[y].first,x);
            LR[y].second = max(LR[y].second,x);
            DU[x].first = min(DU[x].first,y);
            DU[x].second = max(DU[x].second,y);
        }
        int ans = 0;
        for(auto b: buildings){
            int x = b[0];
            int y = b[1];
            if(DU[x].first < y && y < DU[x].second && LR[y].first < x && x < LR[y].second)ans++;
        }
        return ans;
    }
};