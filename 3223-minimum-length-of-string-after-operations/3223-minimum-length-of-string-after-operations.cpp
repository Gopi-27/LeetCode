class Solution {
public:
    int minimumLength(string s) {
        vector<int>Frr(26);
        for(char& ch : s)Frr[ch - 'a']++;
        int cnt = 0;
        for(int i = 0; i < 26; i++){
            if(Frr[i] % 2 == 1)cnt++;
            else cnt += min(Frr[i],2);
        }
        return cnt;
    }
};