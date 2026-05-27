class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int>aFrr(26,-1),AFrr(26,-1);
        int n = word.size();
        for(int i = 0; i < n; i++){
            if(word[i] >= 'a' && word[i] <= 'z')aFrr[word[i] - 'a'] = i;
            else {
                if(AFrr[word[i] - 'A'] == -1)AFrr[word[i] - 'A'] = i;
            }
        }
        int cnt = 0;
        for(int i = 0; i < 26; i++){
            if(aFrr[i] != -1 && AFrr[i] != -1 && aFrr[i] < AFrr[i])cnt++;
        }
        return cnt;
    }
};