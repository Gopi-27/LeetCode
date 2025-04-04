string Convert(int num){
    string str = "";
    while(num > 0){
        int rem = num % 10;
        char ch = rem + '0';
        str = ch + str;
        num /= 10;
    }
    return str;
}
class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> Ans;
        for(int i = 1; i <= n; i++){
            if(i % 3 == 0 && i % 5 == 0)Ans.push_back("FizzBuzz");
            else if(i % 3 == 0 )Ans.push_back("Fizz");
            else if(i % 5 == 0)Ans.push_back("Buzz");
            else Ans.push_back(Convert(i));
        }
        return Ans;
    }
};