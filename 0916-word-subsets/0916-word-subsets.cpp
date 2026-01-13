class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int>mask(26);
        for(string & s: words2){
            vector<int>freq(26);
            for(char & c : s){
                freq[c - 'a']++;
            }
            for(int i = 0; i < 26; i++)mask[i] = max(mask[i],freq[i]);
        }
        vector<string>ans;
        for(string & s : words1){
            vector<int>freq(26);
            for(char & c : s){
                freq[c - 'a']++;
            }
            bool flag = 1;
            for(int i = 0; i < 26; i++){
                if(freq[i] < mask[i]){
                    flag = 0;
                    break;
                }
            }
            if(flag)ans.push_back(s);

        }
        return ans;
    }
};