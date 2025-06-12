class Solution {
public:
    int GetMax(vector<vector<int>>& matrix,int rows,int col){
        int maxi = matrix[0][col];
        for(int i = 1; i < rows; i++){
            if(matrix[i][col] > maxi)maxi = matrix[i][col];
        }
        return maxi;
    }
    vector<vector<int>> modifiedMatrix(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        for(int j = 0; j < cols; j++){
            int maxi = GetMax(matrix,rows,j);
            for(int i = 0; i < rows; i++){
                if(matrix[i][j] == -1)matrix[i][j] = maxi;
            }
        }
        return matrix;
    }
};