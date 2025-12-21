class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs[0].size();
        vector<bool>Memo(n);
        int ans = 0;
        for(int i = 1; i < strs.size(); i++){
            for(int j = 0; j < n; j++){
                if(Memo[j])continue;
                if(strs[i - 1][j] < strs[i][j])break;
                if(strs[i - 1][j] > strs[i][j]){
                    ans++;
                    Memo[j] = 1;
                }
            }
        }
        return ans;
    }
};