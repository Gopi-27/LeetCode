class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>>Pref(n,vector<int>(m + 1));
        for(int i = 0; i < n; i++){
            for(int j = 1; j <= m; j++){
                Pref[i][j] = Pref[i][j - 1] + mat[i][j - 1];
                // cout << Pref[i][j] << " ";
            }
            // cout << endl;
        }
        vector<vector<int>>ans(n,vector<int>(m));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                for(int r = max(0,i - k); r <= min(n - 1,i + k); r++){
                    ans[i][j] += Pref[r][min(m,j + k + 1)] - Pref[r][max(0,j - k)];
                }
            }
        }
        return ans;
    }
};