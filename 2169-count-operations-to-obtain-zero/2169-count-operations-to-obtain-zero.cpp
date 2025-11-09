class Solution {
public:
    int countOperations(int a, int b) {
        int ans = 0;
        while(a != 0 && b != 0){
            if(a > b){
                ans += a/b;
                a %= b;
            }else{
                ans += b/a;
                b %= a;
            }
        }
        return ans;
    }
};