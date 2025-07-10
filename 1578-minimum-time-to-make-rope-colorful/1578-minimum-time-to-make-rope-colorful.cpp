class Solution {
public:
    int minCost(string s, vector<int>& Time) {
        int ans = 0;
        for(int i = 1; s[i] != '\0'; i++){
            if(s[i - 1] == s[i]){
                ans += min(Time[i - 1], Time[i]);
                Time[i] = max(Time[i - 1],Time[i]);
            }
        }
        return ans;
    }
};