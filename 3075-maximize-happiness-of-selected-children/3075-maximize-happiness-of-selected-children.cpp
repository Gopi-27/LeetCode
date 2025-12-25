class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(),happiness.end(),greater<int>());
        int n = happiness.size();
        long long ans = 0;
        for(int i = 0; i < n && i < k; i++){
            ans += max(0,happiness[i] - i);
        }
        return ans;
    }
};