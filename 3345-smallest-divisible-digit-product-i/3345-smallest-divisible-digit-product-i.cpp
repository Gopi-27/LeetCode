class Solution {
public:
    bool ProductMod(int n,int t){
        int pro = 1;
        while(n > 0){
            pro *= n % 10;
            n /= 10;
        }
        return (pro % t) == 0;
    }
    int smallestNumber(int n, int t) {
        while(!ProductMod(n,t))n++;
        return n;
    }
};