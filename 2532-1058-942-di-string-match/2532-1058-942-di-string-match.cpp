class Solution {
public:
    vector<int> diStringMatch(string str) {
        int s = 0;
        int e = str.size();
        vector<int>Ans;
        for(int i = 0; str[i] != '\0'; i++){
            if(str[i] == 'I'){
                Ans.push_back(s++);
            }else{
                Ans.push_back(e--);
            }
        }
        Ans.push_back(e);
        return Ans;

    }
};