class Solution {
public:
    vector<string> splitWordsBySeparator(vector<string>& words, char separator) {
        vector<string>Ans;
        int len = words.size();
        for(int i = 0; i < len; i++){
            int j = 0;
            while(words[i][j] != '\0'){
                string temp = "";
                while( words[i][j] != '\0' && words[i][j] != separator){
                    temp += words[i][j];
                    j++;
                }
                if(temp.size() > 0)Ans.push_back(temp);
                if(words[i][j] == separator)j++;
            }
            
        }
        return Ans;


    }
};