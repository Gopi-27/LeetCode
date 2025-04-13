class Solution {
public:
    string baseNeg2(int n) {
        if(n == 0)return "0";
        string Ans = "";
        while(n != 1){
            int quo = n / (-2);
            int rem = n - (quo * (-2));
            if(rem == 0)Ans = '0' + Ans;
            else{
                if(rem < 0)quo++;
                Ans = '1' + Ans;
            }
            n = quo;
        }
        Ans = '1' + Ans;
        return Ans;
    }
};