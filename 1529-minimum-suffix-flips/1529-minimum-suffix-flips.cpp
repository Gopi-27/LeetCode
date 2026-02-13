class Solution {
public:
    int minFlips(string target) {
        int ans = 0;
        int n = target.size();
        bool flag = 0;
        for(int i = 0; i < n; i++){
            if(flag){
                if(target[i] == '0'){
                    ans++;
                    flag = 0;
                }
            }else{
                if(target[i] == '1'){
                    ans++;
                    flag = 1;
                }
            }
        }
        return ans;
    }
};