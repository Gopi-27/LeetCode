class Solution {
public:
    int numTrees(int n) {
        vector<int>Memo(n + 1,0);
        Memo[0] = 1;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= i; j++){
                Memo[i] += (Memo[j - 1] * Memo[i - j]);
            }
        }
        return Memo[n];
    }
};