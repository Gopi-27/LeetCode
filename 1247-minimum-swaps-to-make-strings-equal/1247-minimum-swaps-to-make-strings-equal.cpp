class Solution {
public:
    int minimumSwap(string s1, string s2) {
        int n = s1.size();
        int xycnt = 0;
        int yxcnt = 0;
        for(int i = 0; i < n; i++){
            if(s1[i] == s2[i])continue;
            if(s1[i] == 'x')xycnt++;
            else yxcnt++;
        }
        if((xycnt + yxcnt) % 2 != 0)return -1;
        int ans = xycnt/2 + yxcnt/2;
        xycnt %= 2;
        yxcnt %= 2;
        ans += (xycnt + yxcnt);
        return ans;      
    }
};