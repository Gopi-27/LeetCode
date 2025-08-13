class Solution {
public:
    int countBinarySubstrings(string s) {
        int ans = 0;
        int n = s.size();
        int prevcnt = 0;
        int i = 0;
        int curcnt = 0;
        while(i < n){
            curcnt = 1;
            i++;
            while(i < n && s[i] == s[i - 1]){
                i++;
                curcnt++;
            }
            ans += min(prevcnt,curcnt);
            prevcnt = curcnt;
        }
        return ans;
    }
};