class Solution {
public:
    string makeFancyString(string s) {
        string ans = "";
        int i = 1;
        int cnt = 1;
        ans += s[0];
        int n = s.size();
        // l e e e t c o d e
        while(i < n){
            if(s[i] == s[i - 1]){
                cnt++;
                if(cnt < 3){
                    ans += s[i];
                }
            }else{
                ans += s[i];
                cnt = 1;
            }
            i++;
        }
        return ans;
    }
};