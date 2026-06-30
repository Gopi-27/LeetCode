class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int acnt = 0;
        int bcnt = 0;
        int ccnt = 0;
        int l = 0;
        int ans = 0;
        for(int r = 0; r < n; r++){
            if(s[r] == 'a')acnt++;
            else if(s[r] == 'b')bcnt++;
            else ccnt++;
            while(acnt && bcnt && ccnt){
                ans += n - r;
                if(s[l] == 'a')acnt--;
                else if(s[l] == 'b')bcnt--;
                else ccnt--;
                l++;                
            }
        }
        return ans;
    }
};