    string Ans = "";
int AddBit(int sum){
    if(sum == 0){
        Ans = '0' + Ans;
        return 0;
    }
    if(sum == 1){
        Ans = '1' + Ans;
        return 0;
    }
    if(sum == 2){
        Ans = '0' + Ans;
        return 1;
    }
    Ans = '1' + Ans;
    return 1;
}


class Solution {
public:
    string addBinary(string a, string b) {
         Ans = "";
        int i = a.size() - 1;
        int j = b.size() - 1;
        int carry = 0;
        while(i >= 0 && j >= 0){
            int sum = (a[i] - '0') + (b[j] - '0') + carry;
            carry = AddBit(sum);
            i--;
            j--;
        }
        while(i >= 0){
            int sum = (a[i] - '0') + carry;
            carry = AddBit(sum);
            i--;
        }
        while(j >= 0){
            int sum = (b[j] - '0') + carry;
            carry = AddBit(sum);
            j--;
        }
        if(carry == 1)Ans = '1' + Ans;
        return Ans;

    }
};