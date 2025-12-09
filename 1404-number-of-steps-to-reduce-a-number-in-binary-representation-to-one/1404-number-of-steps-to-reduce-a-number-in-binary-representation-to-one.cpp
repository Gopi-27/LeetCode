class Solution {
public:
    int numSteps(string s) {
        int cnt = 0;
        int n = s.size();
        bool xchange = 0;
        for(int i = n - 1; i >= 0; i--){
            if(!xchange){
                if(s[i] == '1'){
                    if(i == 0)return cnt;
                    xchange = 1;
                    cnt += 2;
                }else cnt++;
            }else{
                if(s[i] == '0'){
                    cnt++;
                    if(i == 0)return cnt;
                    cnt++;
                }else cnt++;
                
            }
        }
        return cnt;
    }
};