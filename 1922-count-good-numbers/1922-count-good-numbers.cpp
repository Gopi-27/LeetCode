class Solution {
public:
    int mod = 1e9 + 7;
    long long binPow(long long base,long long exp){
        if(exp == 0)return 1;
        if(exp % 2 == 0)return (binPow((base * base) % mod,exp >> 1)) % mod;
        return (base * binPow(base,exp - 1)) % mod;
    }
    int countGoodNumbers(long long n) {
        return (binPow(5,(n + 1) >> 1) * binPow(4,n >> 1)) % mod;
    }
};