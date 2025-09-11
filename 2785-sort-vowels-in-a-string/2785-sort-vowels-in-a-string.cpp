class Solution {
public:
    bool IsVowel(char ch){
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')return 1;
        return 0;
    }
    string sortVowels(string s) {
        string v;
        int n = s.size();
        for(int i = 0; i < n; i++){
            if(IsVowel(s[i])){
                v += s[i];
            }
        }
        sort(v.begin(),v.end());
        int idx = 0;
        for(int i = 0; i < n; i++){
            if(IsVowel(s[i])){
                s[i] = v[idx++];
            }
        }
        return s;
    }
};