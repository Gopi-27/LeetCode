class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int time = 0;
        int n = tickets.size();
        for(int i = 0; i <= k; i++){
            if(tickets[i] <= tickets[k])time += tickets[i];
            else time += tickets[k];
        }
        for(int i = k + 1; i < n; i++){
            if(tickets[i] <= tickets[k] - 1)time += tickets[i];
            else time += tickets[k] - 1;
        }
        return time;
    }
};