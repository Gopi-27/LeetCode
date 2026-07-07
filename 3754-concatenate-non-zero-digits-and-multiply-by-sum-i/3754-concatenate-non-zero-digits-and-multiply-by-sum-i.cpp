class Solution {
public:
    pair<long long,int> Reverse(long long n){
        long long rev = 0;
        int sum = 0;
        while(n > 0){
            int rem = n % 10;
            sum += rem;
            if(rem)rev = (rev * 10) + rem;
            n /= 10;
        }
        return {rev,sum};
    }
    long long sumAndMultiply(int n) {
        pair<long long,int>p = Reverse(Reverse(n).first);
        return 1ll * p.first * p.second;
    }
};