class Solution {
public:
    int generateKey(int num1, int num2, int num3) {
        int ans = 0;
        int exp = 1;
        while(num1 > 0 || num2 > 0 || num3 > 0){
            int mini = min(num1 % 10, num2 % 10);
            mini = min(mini,num3 % 10);
            ans = (mini * exp) + ans;
            exp *= 10;
            num1 /= 10;
            num2 /= 10;
            num3 /= 10;
        }
        return ans;


    }
};