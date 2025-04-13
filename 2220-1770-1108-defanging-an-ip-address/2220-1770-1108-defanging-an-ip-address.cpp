class Solution {
public:
    string defangIPaddr(string address) {
        string Ans = "";
        for(int i = 0; address[i] != '\0'; i++){
            if(address[i] == '.')Ans += "[.]";
            else Ans += address[i];
        }
        return Ans;
    }
};