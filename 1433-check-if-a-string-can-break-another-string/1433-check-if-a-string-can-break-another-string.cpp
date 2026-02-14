class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
        sort(s1.begin(),s1.end());
        sort(s2.begin(),s2.end());
        bool up = true;
        bool down = true;
        int n = s1.size();
        for(int i = 0; i < n; i++){
            if(s1[i] < s2[i])up = 0;

            if(s1[i] > s2[i])down = 0;
        }
        return up | down;
    }
};