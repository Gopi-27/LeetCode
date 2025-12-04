class Solution {
public:
    int countCollisions(string s) {
        int ans = 0;
        bool lblock = false;
        int curr_right = 0;
        int n = s.size();
        for(int i = 0; i < n; i++){
            if(s[i] == 'L'){
                if(curr_right){
                    ans += 2;
                    ans += curr_right - 1;
                    curr_right = 0;
                    lblock = true;
                }else if(lblock){
                    ans += 1;
                }
            }else if(s[i] == 'R'){
                curr_right++;
            }else{
                lblock = true;
                ans += curr_right;
                curr_right = 0;
            }
        }
        return ans;
    }
};