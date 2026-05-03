class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.size();
        for(int i = 0; i < n; i++){
            s += s[0];
            s.erase(s.begin());
            if(s == goal)return true;
        }
        return false;
    }
};