class Solution {
public:
    int mod = 1e9 + 7;
    int numWays(string s) {
        int n = s.size();
        int ocnt = 0;
        for(int i = 0; i < n; i++)if(s[i] == '1')ocnt++;
        if(ocnt % 3)return 0;
        if(!ocnt)return ((1ll * (n - 1) * (n - 2)) >> 1) % mod;
        int k = ocnt/3;
        int i = 0;
        while(k > 0)if(s[i++] == '1')k--;
        int left = 1;
        while(s[i++] == '0')left++;
        k = ocnt/3;
        i = n - 1;
        while(k > 0)if(s[i--] == '1')k--;
        int right = 1;
        while(s[i--] == '0')right++;
        return (1ll * left * right) % mod;
    }
};