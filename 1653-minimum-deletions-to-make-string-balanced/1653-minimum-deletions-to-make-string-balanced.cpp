class Solution {
public:
    int minimumDeletions(string s) {
        int acnt = 0;
        int bcnt = 0;
        int n = s.size();
        for(int i = 0; i < n; i++){
            if(s[i] == 'a')acnt++;
        }
        int ans = INT_MAX;
        for(int i = 0; i < n; i++){
            ans = min(ans,bcnt + acnt);
            if(s[i] == 'a')acnt--;
            else bcnt++;
        }
        ans = min(ans,bcnt + acnt);
        return ans;
    }
};