class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        map<int,int>mpp;
        int n = score.size();
        for(int i = 0; i < n; i++){
            mpp[score[i]] = i;
        }
        vector<string>ans(n);
        char rank = n;
        for(auto b: mpp){
            if(n <= 3){
                if(n == 1)ans[b.second] = "Gold Medal";
                else if(n == 2)ans[b.second] = "Silver Medal";
                else ans[b.second] = "Bronze Medal";
            }else ans[b.second] = to_string(n);
            n--;
        }
        return ans;
    }
};