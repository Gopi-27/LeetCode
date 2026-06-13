class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        int n = words.size();
        vector<int>Sum;
        for(auto s : words){
            int cnt = 0;
            for(auto c : s){
                cnt += weights[c - 'a'];
            }
            Sum.push_back(cnt);
        }
        string ans = "";
        for(int i = 0; i < n; i++){
            int w = Sum[i]  % 26;
            ans += 'z' - w;
            
        }
        return ans;
    }
};