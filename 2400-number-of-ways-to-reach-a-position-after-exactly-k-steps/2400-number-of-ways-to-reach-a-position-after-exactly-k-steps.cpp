class Solution {
public:
    int p = 1e9 + 7;
    long long Fact(int n){
        long long f = 1;
        for(int i = n; i >= 2; i--)f = (f * i) % p;
        return f;
    }
    long long binPow(long long base, int exp){
        if(exp == 0)return 1;
        if(exp % 2)return (base * binPow(base,exp - 1)) % p;
        return binPow((base * base) % p,exp/2) % p;
    }
    int numberOfWays(int startPos, int endPos, int k) {
        int req = abs(endPos - startPos);
        if(req > k)return 0;
        k -= req;
        if(k % 2)return 0;
        cout << Fact(k + req) << endl;
        cout << binPow(k/2,p - 2) << endl;
        cout << binPow(k/2 + req,p - 2) << endl;
        return (((Fact(k + req) * binPow(Fact(k/2),p - 2)) % p) * binPow(Fact(k/2 + req),p - 2)) % p;
        
    }
};