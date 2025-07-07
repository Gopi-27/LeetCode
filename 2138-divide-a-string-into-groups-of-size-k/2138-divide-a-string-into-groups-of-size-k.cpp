class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string>Ans;
        int i = 0;
        while(s[i] != '\0'){
            string temp = "";
            int cnt = k;
            while(s[i] != '\0' && cnt){
                cnt--;
                temp += s[i++];
            }
            if(s[i] != '\0')Ans.push_back(temp);
            else{
                while(cnt){
                    cnt--;
                    temp += fill;
                }
                Ans.push_back(temp);
            }
        }
        return Ans;
    }
};