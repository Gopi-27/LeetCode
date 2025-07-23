class Solution {
public:
    int GetCount(string &s,char ch){
        int cnt = 0;
        char val = (ch == 'a')?'b':'a';
        int top = -1;
        int n = s.size();
        for(int i = 0; i < n; i++){
            if(s[i] == ch && top != -1 && s[top] == val){
                top--;
                cnt++;
            }else s[++top] = s[i];
        }
        s.resize(top + 1);
        return cnt;
    }
    int maximumGain(string s, int x, int y) {
        if(x > y)return GetCount(s,'b') * x + GetCount(s,'a') * y;
        return GetCount(s,'a') * y + GetCount(s,'b') * x;
    }
};