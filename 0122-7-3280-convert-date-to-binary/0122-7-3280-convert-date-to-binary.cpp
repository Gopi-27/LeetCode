class Solution {
public:
    string convertDateToBinary(string date) {
        int year = ((date[0] - '0') * 1000 )+ ((date[1] - '0') * 100) + ((date[2] - '0') * 10) + (date[3] - '0');
        int month =((date[5] - '0') * 10) + (date[6] - '0');
        int day = ((date[8] - '0') * 10) + (date[9] - '0');
        int rem ;
        char ch;
        string Ans = "";
        while(day > 1){
            rem = day % 2;
            ch = rem + '0'; 
            Ans = ch + Ans;
            day /= 2;
        }
        Ans = "-1" + Ans;
        while(month > 1){
            rem = month % 2;
            ch = rem + '0'; 
            Ans = ch + Ans;;
            month /= 2;
        }
        Ans = "-1" + Ans;
        while(year > 1){
            rem = year % 2;
            ch = rem + '0'; 
            Ans = ch + Ans;
            year /= 2;
        }
        Ans = "1" + Ans;
        return Ans;
    }
};