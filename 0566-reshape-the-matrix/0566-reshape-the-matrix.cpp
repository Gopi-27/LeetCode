class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m = mat.size();
        int n = mat[0].size();
        if(m * n != r * c)return mat;
        vector<vector<int>>Ans;
        int p1 = 0;
        int p2 = 0;
        while(r--){
            vector<int>dummy;
            for(int i = 0; i < c; i++){
                if(p2 == n){
                    p1++;
                    p2 = 0;
                }
                dummy.push_back(mat[p1][p2]);
                p2++;
            }
            Ans.push_back(dummy);
        }
        return Ans;
    }
};