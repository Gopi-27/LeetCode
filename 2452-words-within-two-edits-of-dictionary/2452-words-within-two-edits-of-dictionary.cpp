class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string>ans;
        int n = queries[0].size();
        for(string& s : queries){
            for(string& w : dictionary){
                int cnt = 0;
                for(int i = 0; i < n; i++){
                    if(s[i] != w[i])cnt++;
                    if(cnt > 2)break;
                }
                if(cnt <= 2){
                    ans.push_back(s);
                    break;
                }
            }
        }
        return ans;
    }
};