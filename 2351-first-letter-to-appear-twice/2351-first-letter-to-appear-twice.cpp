class Solution {
public:
    char repeatedCharacter(string s) {
        int frr[26] = {0};
        for(int i = 0; s[i] != '\0'; i++){
            if(frr[s[i] - 'a'] == 1)return s[i];
            else frr[s[i] - 'a']++;
        }
        return '\0';
    }
};