class Solution {
public:
    string processStr(string s) {
        string ans = "";
        for(int i = 0; s[i] != '\0'; i++){
            if(s[i] == '*'){
                int len = ans.size();
                if(len)ans.pop_back();
            }else if(s[i] == '#'){
                ans += ans;
            }else if(s[i] == '%'){
                reverse(ans.begin(),ans.end());
            }else{
                ans += s[i];
            }
            cout << ans << endl;
        }
        return ans;
    }
};