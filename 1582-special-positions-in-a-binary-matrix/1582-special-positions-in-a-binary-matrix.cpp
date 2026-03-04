class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<int>Row(n),Col(m);
        for(int i = 0; i < n; i++){
            int cnt = 0;
            for(int j = 0; j < m; j++)if(mat[i][j])cnt++;
            Row[i] = cnt;
        }
        for(int j = 0; j < m; j++){
            int cnt = 0;
            for(int i = 0; i < n; i++){
                if(mat[i][j])cnt++;
            }
            Col[j] = cnt;
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(Row[i] == 1 && Col[j] == 1 && mat[i][j] == 1)ans++;
            }
        }
        return ans;
    }
};