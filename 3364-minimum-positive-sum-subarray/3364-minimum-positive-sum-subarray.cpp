class Solution {
public:
    int minimumSumSubarray(vector<int>& pref, int l, int r) {
        bool flag = 0;
        int n = pref.size();
        for(int i = 1; i < n; i++)pref[i] += pref[i - 1];
        int ans = INT_MAX;
        for(int k = l; k <= r; k++){
            int sum = pref[k - 1];
            if(sum > 0){
                flag = 1;
                ans = min(ans,sum);
            }
            for(int i = k; i < n; i++){
                sum = pref[i] - pref[i - k];
                if(sum > 0){
                    flag = 1;
                    ans = min(ans,sum);
                }
            }
        }
        if(flag)return ans;
        return -1;
    }
};