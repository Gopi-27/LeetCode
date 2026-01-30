class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int i = 0;
        int j = 0;
        while(1){
            //i,j
            // top

            if(i > 0){
                if(mat[i - 1][j] > mat[i][j]){
                    i = i - 1;
                    continue;
                }
            }
            // left
            if(j > 0){
                if(mat[i][j - 1] > mat[i][j]){
                    j--;
                    continue;
                }
            }

            //bott
            if(i < n - 1){
                if(mat[i + 1][j] > mat[i][j]){
                    i++;
                    continue;
                }
            }
            // right
            if(j < m - 1){
                if(mat[i][j + 1] > mat[i][j]){
                    j++;
                    continue;
                }
            }

            return {i,j};
        }
        return {-1,-1};
    }
};