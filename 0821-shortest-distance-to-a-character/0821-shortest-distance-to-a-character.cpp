class Solution {
public:
    int GetIdx(string & s,char ch,int start){
        for(int i = start; s[i] != '\0'; i++){
            if(s[i] == ch)return i;
        }
        return INT_MAX;
    }
    vector<int> shortestToChar(string s, char ch) {
        int left = INT_MAX;
        int i = 0;
        int n = s.size();
        int right = - 1;
        vector<int>Ans(n);
        while(i < n){
            right = GetIdx(s,ch,right + 1);
            while(i < n && i <= right){
                Ans[i] = min(abs(left - i),abs(right - i));
                i++;
            }
            left = right;
        }
        return Ans;
       

    }
};