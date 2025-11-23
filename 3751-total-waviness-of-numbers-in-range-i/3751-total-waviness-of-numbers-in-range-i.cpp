class Solution {
public:
    int AddScore(int a,int b,int c){
        if(b > a && b > c)return 1;
        if(b < a && b < c)return 1;
        return 0;
    }
    int totalWaviness(int num1, int num2) {
        int ans = 0;
        for(int i = num1; i <= num2; i++){
            if(i <= 100)continue;
            int n = i;
            int after = n % 10;
            n /= 10;
            int curr = n % 10;
            n /= 10;
            int prev = n % 10;
            ans += AddScore(prev,curr,after);
            while(n > 9){
                after = curr;
                curr = prev;
                n /= 10;
                prev = n % 10;
                ans += AddScore(prev,curr,after);
            }
        }
        return ans;
    }
};