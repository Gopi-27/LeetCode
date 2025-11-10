class Solution {
public:
    int uniquePaths(int n, int m) {
        if(n == 1)return 1;
        // space optimization
        vector<int>prev(m,1);
        vector<int>curr(m);
        for(int i = 1; i < n; i++){
            curr[0] = 1;
            for(int j = 1; j < m; j++){
               curr[j] = curr[j - 1] + prev[j];
            }
            prev = curr;
        }
        return curr[m - 1];
    }
};