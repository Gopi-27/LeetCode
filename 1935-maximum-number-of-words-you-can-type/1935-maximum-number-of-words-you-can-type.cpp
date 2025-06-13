class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        vector<bool>on_off(26);
        for(auto s : brokenLetters)on_off[s - 'a'] = true;
        // on -> 0
        // off -> 1
        int ans = 0;
        int i = 0;
        while(text[i] != '\0'){
            bool flag = true;
            while(text[i] != ' ' && text[i] != '\0'){
                if(on_off[text[i] - 'a']){
                    flag = false;
                    break;
                }
                i++;
            }
            if(flag)ans++;
            else{
                while(text[i] != ' ' && text[i] != '\0')i++;
            }
            if(text[i] == ' ')i++;
        }
        return ans;
    }
};