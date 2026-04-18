class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int l = 0;
        unordered_map<char,int>mpp;
        int ans = 0;
        for(int r = 0; r < n; r++){
            while(mpp.count(s[r]))mpp.erase(s[l++]);
            mpp[s[r]]++;
            ans = max(ans,r - l + 1);
        }  
        return ans;     
    }
};