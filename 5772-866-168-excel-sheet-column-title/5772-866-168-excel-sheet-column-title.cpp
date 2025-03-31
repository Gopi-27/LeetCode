class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans = "";
        while(columnNumber > 26){
            int rem = columnNumber % 26;
            if(rem == 0){
                columnNumber /= 26;
                columnNumber--;
                rem = 26;
            }else{
                columnNumber /= 26;
            }
            char val = 'A' + rem - 1;
            ans = val + ans;
        }
        if(columnNumber > 0){
            char val = 'A' + columnNumber - 1;
            ans = val + ans;
        }
        return ans;
    }
};