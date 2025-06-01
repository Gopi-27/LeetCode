class Solution {
public:
    bool checkString(string s) {
        int idx = 0;
        while(s[idx] == 'a')idx++;
        while(s[idx] != '\0'){
            if(s[idx] == 'a')return false;
            idx++;
        }
        return true;
    }
};