class Solution {
public:
    int maxDistinct(string s) {
        vector<bool>freq(26);
        int cnt = 1;
        freq[s[0] - 'a'] = 1;
        for(int i = 1; i < s.size(); i++){
            if(!freq[s[i] - 'a']){
                freq[s[i] - 'a'] = 1;
                cnt++;
            }
        }
        return cnt;
    }
};