class Solution {
public:
    int minAddToMakeValid(string s) {
        int n = s.size();
        int cnt = 0;
        int mvs = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == '(')cnt++;
            else if(!cnt)mvs++;
            else cnt--;
        }
        return mvs + cnt;
    }
};