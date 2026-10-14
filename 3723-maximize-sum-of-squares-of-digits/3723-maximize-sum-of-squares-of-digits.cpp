class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if(9ll * num < sum)return "";
        string ans = "";
        int quo = sum/9;
        for(int i = 0; i < quo; i++)ans += '9';
        if(quo == num)return ans;
        ans += '0' + sum % 9;
        for(int i = quo + 1; i < num; i++)ans += '0';
        return ans;
    }
};