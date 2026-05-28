class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        long long ans = 0;
        vector<int>InDeg(n);
        for(vector<int>& r : roads){
            InDeg[r[0]]++;
            InDeg[r[1]]++;
        }
        sort(InDeg.begin(),InDeg.end());
        for(int i = 0; i < n; i++)ans += 1ll * (i + 1) * InDeg[i];
        return ans;
    }
};