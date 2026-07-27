class Solution {
public:
    long long minimumSteps(string s) {
        long long ans = 0;
        int n = s.size();
        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == '1')cnt++;
            else ans += cnt;
        }
        return ans;
    }
};