class Solution {
public:
    int GetPro(int n){
        if(n < 0)return 0;
        if(n <= 2)return n;
        return n * (n - 1)/(n - 2); 
    }
    int clumsy(int n) {
        if(n <= 2)return n;
        int ans = n * (n - 1)/(n - 2);
        for(int i = n - 3; i >= 1; i -= 4){
            ans += i;
            ans -= GetPro(i - 1);
        }
        return ans;
    }
};