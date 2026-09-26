class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        int n = s.size();
        map<string,string>mpp;
        for(vector<string>& b : knowledge)mpp[b[0]] = b[1];
        string ans = "";
        int i = 0;
        while(i < n){
            while(i < n && s[i] != '(')ans += s[i++];
            string key = "";
            i++;
            while(i < n && s[i] != ')')key += s[i++];
            i++;
            if(mpp.count(key))ans += mpp[key];
            else if(key.size() > 0)ans += '?';
        }
        return ans;
    }
};