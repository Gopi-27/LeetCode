class Solution {
public:
    bool IsVowel(char ch){
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' ||ch == 'u')return 1;
        return 0;
    }
    bool doesAliceWin(string s) {
        for(char ch : s)if(IsVowel(ch))return true;
        return false;
    }
};