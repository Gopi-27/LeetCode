class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        int mini = 27;
        for(int i = 0; i < n; i++){
            if(s[i] != 'a'){
                if((s[i] - 'a' + 1) < mini)mini = s[i] - 'a' + 1;
            }
        }
        return 27 - mini;
    }
};