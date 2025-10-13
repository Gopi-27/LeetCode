class Solution {
public:
    bool Valid(string A, string B){
        sort(A.begin(),A.end());
        sort(B.begin(),B.end());
        return A == B;
    }
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string>Ans;
        Ans.push_back(words[0]);
        int n = words.size();
        for(int i = 1; i < n; i++){
            if(!Valid(Ans[Ans.size() - 1],words[i])){
                Ans.push_back(words[i]);
            }
        }
        return Ans;
    }
};