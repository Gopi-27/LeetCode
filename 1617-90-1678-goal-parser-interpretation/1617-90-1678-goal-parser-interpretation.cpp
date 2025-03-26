class Solution {
public:
    string interpret(string command) {
        int len = command.size();
        int r = 0;
        string ans = "";
        while(r < len){
            if(command[r] == 'G'){
                ans = ans + 'G';
                r++;
            }else if(command[r] == '(' && command[r + 1] == ')'){
                ans = ans + 'o';
                r = r + 2;
            }else{
                ans = ans + "al";
                r = r + 4;
            }
        }
        return ans;

    }
};