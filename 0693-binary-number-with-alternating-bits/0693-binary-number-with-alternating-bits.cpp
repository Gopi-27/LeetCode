class Solution {
public:
    bool hasAlternatingBits(int n) {
        bool flag = 0;
        if(n % 2 == 1)flag = 1;
        while(n > 0){
            if(n % 2 == flag){
                flag = !flag;
                n >>= 1;
                continue;
            }
            return false;
        }
        return true;
    }
};