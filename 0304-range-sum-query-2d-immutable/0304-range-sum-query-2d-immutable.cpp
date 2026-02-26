class NumMatrix {
public:
    vector<vector<int>>mat;
    NumMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int>A(m + 1);
        mat.push_back(A);
        for(int i = 1; i <= n; i++){
            vector<int>B(m + 1);
            for(int j = 1; j <= m; j++){
                B[j] = matrix[i - 1][j - 1] + B[j - 1] + mat[i - 1][j] - mat[i - 1][j - 1];
            }
            mat.push_back(B);
        }

        // for(int i = 1; i <= n; i++){
        //     for(int j = 1; j <= m; j++){
        //         cout << mat[i][j] << " ";
        //     }
        //     cout << endl;
        // }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return mat[row2 + 1][col2 + 1] - mat[row2 + 1][col1] - mat[row1][col2 + 1] + mat[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */