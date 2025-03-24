class Solution {
public:
    char findTheDifference(string s, string t) {
        map<char,int>mpp;
        char ans;
        for(auto ch : s)mpp[ch]++;
        for(auto ch : t)mpp[ch]++;
        for(auto i : mpp){
            if(i.second % 2 == 1){
                ans = i.first;
                break;
            }
        }
        return ans;
    }
};