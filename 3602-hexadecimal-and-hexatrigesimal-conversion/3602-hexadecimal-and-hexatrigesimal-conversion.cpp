class Solution {
public:
    string Convert(int val ,int base){
        string Ans = "";
        while(val > 0){
            int rem = val % base;
            if(rem <= 9)Ans += rem + '0';
            else Ans += 'A' + (rem - 10);
            val /= base;
        }
        reverse(Ans.begin(),Ans.end());
        return Ans;
    }
    string concatHex36(int n) {
        string Ans = "";
        Ans += Convert(n * n,16);
        Ans += Convert(n * n * n, 36);
        return Ans;
    }
};