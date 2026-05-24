class Solution {
public:
    int passwordStrength(string password) {
        map<char,int>mpp;
        for(char& c : password)mpp[c]++;
        int scr = 0;
        for(auto b : mpp){
            if(b.first >= 'a' && b.first <= 'z')scr++;
            else if(b.first >= 'A' && b.first <= 'Z')scr += 2;
            else if(b.first >= '0' && b.first <= '9')scr += 3;
            else scr += 5;
        }
        return scr;
    }
};