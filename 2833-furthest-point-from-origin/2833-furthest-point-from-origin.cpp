class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int cnt = 0;
        int pos = 0;
        for(char& ch : moves){
            if(ch == 'R')pos++;
            else if(ch == 'L')pos--;
            else cnt++;
        }
        return abs(pos) + cnt;
    }
};