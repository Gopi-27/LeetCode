class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int prev = groups[0];
        vector<string>Ans;
        Ans.push_back(words[0]);
        int n = groups.size();
        for(int i = 1; i < n; i++){
            if(groups[i] != prev){
                Ans.push_back(words[i]);
                prev = groups[i];
            }
        }
        return Ans;
    }
};