class Solution {
public:
    bool isFascinating(int n) {
        int frr[10] = {0};
        int n2 = 2 * n;
        int n3 = 3 * n;
        while(n){
            int rem = n % 10;
            if(rem == 0 || frr[rem] == 1)return false;
            else frr[rem]++;
            n /= 10;
        }
        while(n2){
            int rem = n2 % 10;
            if(rem == 0 || frr[rem] == 1)return false;
            else frr[rem]++;
            n2 /= 10;
        }
        while(n3){
            int rem = n3 % 10;
            if(rem == 0 || frr[rem] == 1)return false;
            else frr[rem]++;
            n3 /= 10;
        }
        return true;
    }
};