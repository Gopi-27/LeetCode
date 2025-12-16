class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int>freq(26);
        int n = s.size();
        for(int i = 0; i < n; i++)freq[s[i] - 'a']++;
        string str1;
        for(int i = 0; i < 26; i++){
            for(int j = 0; j < freq[i]/2; j++){
                str1 += (char)('a' + i);
            }
        }
        string str2 = str1;
        reverse(str2.begin(),str2.end());
        if(n % 2 == 0)return str1 + str2;
        return str1 + s[n/2] + str2;
    }
};