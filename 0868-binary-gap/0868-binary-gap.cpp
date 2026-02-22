class Solution {
public:
    int binaryGap(int n) {
        int ans = 0;
        while(n % 2 == 0)n >>= 1;
        n >>= 1;
        while(n > 0){
            int cnt = 1;
            while(n > 0 && n % 2 == 0){
                cnt++;
                n >>= 1;
            }
            ans = max(ans,cnt);
            n >>= 1;
        }
        return ans;
    }
};