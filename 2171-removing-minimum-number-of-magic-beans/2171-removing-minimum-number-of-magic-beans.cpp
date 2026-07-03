class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        sort(beans.begin(),beans.end());
        int n = beans.size();
        long long pref = 0,suff = 0;
        for(int i = 0; i < n; i++)pref += beans[i];
        long long ans = LLONG_MAX;
        for(int i = n - 1; i >= 0; i--){
            pref -= beans[i];
            suff += beans[i];
            ans = min(ans, pref + suff - 1ll * (n - i) * beans[i]);
        }
        return ans;
    }
};