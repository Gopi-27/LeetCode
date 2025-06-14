class Solution {
public:
    int minMaxDifference(int num) {
        vector<int>digits;
        while(num > 0){
           digits.push_back(num % 10);
            num /= 10;
        }
        int n = digits.size();
        long long max = 0;
        int min = 0;

        int max_exchange;
        bool max_exchange_found = false;
        int min_exchange;
        bool min_exchange_found = false;

        for(int i = n - 1; i >= 0; i--){
            if(max_exchange_found){
                if(digits[i] == max_exchange){
                    max = (max * 10) + 9;
                }else{
                    max = (max * 10) + digits[i];
                }
            }else if(digits[i] != 9){
                max_exchange = digits[i];
                max_exchange_found = true;
                max = (max * 10) + 9;
            }else{
                max = (max * 10) + 9;
            }

            if(min_exchange_found){
                if(min_exchange == digits[i]){
                    min = (min * 10) + 0;
                }else{
                    min = (min * 10) + digits[i];
                }
            }else{
                min_exchange = digits[i];
                min_exchange_found = true;
                min = (min * 10) + 0;
            }


        }
        return max - min;

    }
};