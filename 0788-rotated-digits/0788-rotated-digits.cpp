class Solution {
public:
    vector<int>RDig = {0,1,5,-1,-1,2,9,-1,8,6};
    int Rotate(int n){
        int org = n;
        int exp = 1;
        int x = 0;
        while(n > 0){
            int d = RDig[n % 10];
            if(d == -1)return org;
            x += d * exp;
            exp *= 10;
            n /= 10;
        }
        return x;
    }
    int rotatedDigits(int n) {
        int cnt = 0;
        for(int i = 1; i <= n; i++)if(i != Rotate(i))cnt++;            
        return cnt;
    }
};