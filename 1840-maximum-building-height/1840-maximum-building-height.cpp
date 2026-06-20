class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& rtr) {
        rtr.push_back({1,0});
        sort(rtr.begin(),rtr.end());
        int l = rtr.size();
        if(rtr[l - 1][0] != n)rtr.push_back({n,n - 1});
        l = rtr.size();
        for(int i = l - 2; i >= 0; i--){
            int d = rtr[i + 1][0] - rtr[i][0];
            rtr[i][1] = min(rtr[i][1],rtr[i + 1][1] + d);
        }
        int ans = 0;
        for(int i = 1; i < l; i++){
            int d = rtr[i][0] - rtr[i - 1][0];
            rtr[i][1] = min(rtr[i][1],rtr[i - 1][1] + d);
            ans = max(ans,(d + abs(rtr[i - 1][1] + rtr[i][1]))/2);
        }
        return ans;
    }
};