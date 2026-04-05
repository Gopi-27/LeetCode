class Solution {
public:
    int mirrorFrequency(string s) {
        int n = s.size();
        vector<int>Crr(26),Drr(10);
        for(int i = 0; i < n; i++){
            if(s[i] >= 'a' && s[i] <= 'z')Crr[s[i] - 'a']++;
            else Drr[s[i] - '0']++;
        }
        int ans = 0;
        for(int i = 0; i < 13; i++){
            ans += abs(Crr[i] - Crr[26 - i - 1]);
        }
        for(int i = 0; i < 5; i++){
            ans += abs(Drr[i] - Drr[10 - i - 1]);
        }
        return ans;
    }
};