class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs[0].size();
        vector<int>Memo(n);
        for(int i = 0; i < n; i++){
            Memo[i] = strs[0][i] - 'a';
        }
        int cnt = 0;
        for(int j = 1; j < strs.size(); j++){
            for(int i = 0; i < n; i++){
                if(Memo[i] == -1)continue;
                int cur = strs[j][i] - 'a';
                if(Memo[i] <= cur)Memo[i] = cur;
                else {
                    Memo[i] = -1;
                    cnt++;
                }
                
            }
        }
        return cnt;
    }
};