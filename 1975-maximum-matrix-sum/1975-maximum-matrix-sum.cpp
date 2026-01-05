class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        long long sum = 0;
        int mini = abs(matrix[0][0]);
        int ncnt = 0;
        int zcnt = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] > 0)sum += matrix[i][j]; 
                else if(matrix[i][j] < 0){
                    sum -= matrix[i][j];
                    ncnt++;
                }else zcnt++;
                mini = min(mini,abs(matrix[i][j]));
            }
        }
        cout << ncnt << " " << zcnt << " " << sum;
        if(ncnt % 2 == 0)return sum;
        if(zcnt)return sum;
        return sum - 2 * mini;
    }
};