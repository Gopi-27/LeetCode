class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string,int>mpp;
        int idx = 0;
        while(1){
            string temp = "";
            while(s1[idx] != '\0' && s1[idx] != ' ')temp += s1[idx++];
            mpp[temp]++;
            if(s1[idx] == '\0')break;
            else idx++;
        }
        idx = 0;
        while(1){
            string temp = "";
            while(s2[idx] != '\0' && s2[idx] != ' ')temp += s2[idx++];
            mpp[temp]++;
            if(s2[idx] == '\0')break;
            else idx++;
            
        }
        vector<string>ans;
        for(auto b : mpp){
            if(b.second == 1)ans.push_back(b.first);
        }
        return ans;



    }
};