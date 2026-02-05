class Solution {
public:
    long long lastInteger(long long n) {
        long long start = 1;
        long long end = n;
        long long d = 1;
        long long tot = n;
        while(tot > 1){
            long long nStart;
            if(tot % 2 == 0){
                nStart = start + (tot - 2) * d;
            }else{
                nStart = start + (tot - 1) * d;
            }
            cout << nStart << endl;
            start = nStart;
            d *= -2;
            tot = (tot + 1) / 2;
        }
        return start;
    }
};