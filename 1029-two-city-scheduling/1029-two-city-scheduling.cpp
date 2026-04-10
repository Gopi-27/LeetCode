class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n = costs.size();
        int ans = 0;
        vector<int>diff(n);
        for(int i = 0; i < n; i++){
            ans += costs[i][0];
            diff[i] = costs[i][1] - costs[i][0];
        }
        sort(diff.begin(),diff.end());
        for(int i = 0; i < n/2; i++){
            ans += diff[i];
        }
        return ans;
    }
};