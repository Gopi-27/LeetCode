class Solution {
public:
    int maxOperations(string s) {
        int ans = 0;
        int ocnt = 0;
        bool flag = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '0' && flag)continue;
            if(s[i] == '0'){
                flag = 1;
                ans += ocnt;
            }else{
                flag = 0;
                ocnt++;
            }
        }
        return ans;
    }
};