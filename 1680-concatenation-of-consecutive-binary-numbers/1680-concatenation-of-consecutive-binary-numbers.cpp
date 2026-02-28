class Solution {
public:
    int mod = 1e9 + 7;
    int concatenatedBinary(int n) {
        long long ans = 0;
        long long mask = 1;
        for(int i = n; i >= 1; i--){
            int num = i;
            while(num > 0){
                if(num & 1){
                    ans = (ans + mask) % mod;
                }
                mask = (mask << 1) % mod;
                num >>= 1;
            }
        }
        return ans;
    }
};


