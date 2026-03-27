class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        int m = mat[0].size();
        k = k % m;
        vector<vector<int>>org = mat;
        for(int i = 0; i < n; i++){
            vector<int>temp;
            if(i % 2 == 0){
                for(int j = k; j < m; j++)temp.push_back(mat[i][j]);
                for(int j = 0; j < k; j++)temp.push_back(mat[i][j]);
            }else{
                for(int j = m - k; j < m; j++)temp.push_back(mat[i][j]);
                for(int j = 0; j < m - k; j++)temp.push_back(mat[i][j]);
            }
            mat[i] = temp;
        }
        for(int i = 0; i < n; i++){
            cout << "Org -> ";
            for(int j = 0; j < m; j++)cout << org[i][j] << " ";
            cout << endl;
            cout << "New -> ";
            for(int j = 0; j < m; j++)cout << mat[i][j] << " ";
            cout << endl;
        }
        return mat == org;
    }
};