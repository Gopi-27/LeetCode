class Solution {
public:
    int possibleStringCount(string s) {
        int ans = 1;
        for(int i = 1; s[i] != '\0'; i++){
            if(s[i] == s[i - 1])ans++;
        }
        return ans;
    }
};