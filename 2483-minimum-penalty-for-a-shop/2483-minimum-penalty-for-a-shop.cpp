class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        int close_penalty = 0;
        for(int i = 0; i < n; i++)if(customers[i] == 'Y')close_penalty++;

        int open_penalty = 0;
        int min_closing_time = 0;
        int min_penalty = n + 1;
        for(int i = 0; i < n; i++){
            // 0... i - 1 opened
            // i.... closes
            int penalty = open_penalty + close_penalty;
            if(penalty < min_penalty){
                min_penalty = penalty;
                min_closing_time = i;
            }
            if(customers[i] == 'Y')close_penalty--;
            else open_penalty++;
        }
        int penalty = open_penalty + close_penalty;
        if(penalty < min_penalty){
            min_penalty = penalty;
            min_closing_time = n;
        }
        return min_closing_time ;
    }
};