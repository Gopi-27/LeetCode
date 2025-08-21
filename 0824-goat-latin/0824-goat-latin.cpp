class Solution {
public:
    bool IsVowel(char ch){
        if(ch >= 'a'){
            ch = (ch - 'a') + 'A';
        }
        return ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U' ;
    }
    string toGoatLatin(string sentence) {
        string extra = "maa";
        string ans = "";
        int n = sentence.size();
        int i = 0;
        while(i < n){
            int flag = 0;
            char ch;
            if(IsVowel(sentence[i])){
                ans += sentence[i];
            }else{
                flag = 1;
                ch = sentence[i];
            }
            i++;
            while(i < n && sentence[i] != ' '){
                ans += sentence[i];
                i++;
            }
            if(flag)ans += ch;
            ans += extra;
            ans += ' ';
            extra += 'a';
            i++;
        }
        ans.pop_back();
        return ans;

    }
};