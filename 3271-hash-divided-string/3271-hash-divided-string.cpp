class Solution {
public:
    string stringHash(string s, int k) {
        int n = s.size();
        string ans = "";
        for(int i = 0; i < n; i += k){
            int val = 0;
            for(int j = i; j < i + k; j++){
                val += s[j] - 'a';
            }
            ans += (char)('a' + (val % 26));
        }
        return ans;
    }
};