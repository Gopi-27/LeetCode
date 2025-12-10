class Solution {
public:
    int mod = 1e9 + 7;
    int countPermutations(vector<int>& complexity) {
        int idx = 0;
        int n = complexity.size();
        for(int i = 1; i < n; i++){
            if(complexity[i] <= complexity[idx]){
                idx = i;
            }
        }
        if(idx != 0)return 0;
        long long ans = 1;
        for(int i = 2; i < n; i++){
            ans = (ans * i) % mod;
        }
        return ans;
    }
};