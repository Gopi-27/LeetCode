class Solution {
public:
    bool canConstruct(string s, int k) {
        if(s.size() < k)return false;
        map<char,int>mpp;
        for(char & c : s)mpp[c]++;
        int cnt = 0;
        for(auto b : mpp){
            if(b.second % 2 == 1)cnt++;
        }
        return cnt <= k;
    }
};