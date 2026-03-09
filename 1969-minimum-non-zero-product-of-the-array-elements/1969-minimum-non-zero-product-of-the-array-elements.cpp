class Solution {
public:
    int mod = 1e9 + 7;
    long long binPow(long long base,long long expo){
        if(expo == 0)return 1;
        if(expo % 2 == 0) return binPow((1ll * base * base) % mod,expo/2) % mod;
        return (1ll * base * binPow(base,expo - 1)) % mod;
    }
    int minNonZeroProduct(int p) {
        if(p == 1)return 1;
        long long val = (1ll << p);
        return (1ll * binPow((val - 2) % mod,(val - 2)/2) * ((val - 1) % mod)) % mod;
    }
};