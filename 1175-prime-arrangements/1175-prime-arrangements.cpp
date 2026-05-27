class Solution {
public:
    int mod = 1e9 + 7;
    bool isPrime(int n){
        if(n <= 1)return false;
        for(int i = 2; i * i <= n; i++)if(n % i == 0)return false;
        return true;
    }
    int Fact(int n){
        int ans = 1;
        for(int i = n; i >= 1; i--)ans = (1ll * ans * i) % mod;
        return ans;
    }
    int numPrimeArrangements(int n) {
        int pcnt = 0;
        for(int i = 1; i <= n; i++)if(isPrime(i))pcnt++;
        return (1ll * Fact(pcnt) * Fact(n - pcnt)) % mod;        
    }
};