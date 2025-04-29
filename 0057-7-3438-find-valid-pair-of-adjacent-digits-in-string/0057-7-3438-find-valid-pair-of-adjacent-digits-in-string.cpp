class Solution {
public:
    string findValidPair(string s) {
    int frr[10] = {0};
    for(int i = 0; s[i] != '\0'; i++){
        frr[s[i] - '0']++;
    }
    for(int i = 1; s[i] != '\0'; i++){
        if(s[i - 1] != s[i] && frr[s[i - 1] - '0'] == (s[i-1] - '0') && frr[s[i] - '0'] == (s[i] - '0')){
            string Ans = "";
            Ans += s[i - 1] ;
            Ans += s[i];
            return Ans;
        }
    }

    return "";
    }
};