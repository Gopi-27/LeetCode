class Solution {
public:
    long long minArraySum(vector<int>& nums) {
        int n = 100001;
        vector<int>A(n);
        for(int& i : nums)A[i]++;
        vector<bool>Vis(n);
        long long ans = 0;
        for(int i = 1; i < n; i++){
            if(!Vis[i] && A[i]){
                for(int j = i; j < n; j += i){
                    if(!Vis[j])ans += 1ll * A[j] * i;
                    Vis[j] = 1;
                }
            }
        }
        return ans;
    }
};