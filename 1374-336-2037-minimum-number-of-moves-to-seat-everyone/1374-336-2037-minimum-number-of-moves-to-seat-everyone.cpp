class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        sort(seats.begin(),seats.end());
        sort(students.begin(),students.end());
        int n = seats.size();
        int Ans = 0;
        for(int i = 0; i < n; i++){
            Ans += abs(seats[i] - students[i]);
        }
        return Ans;
    }
};