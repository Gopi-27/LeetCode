class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int>Ans;
        vector<int>Row(m);
        vector<int>Col(n);
        for(int i = 0; i < m; i++){
            int mini_idx = 0;
            for(int j = 1; j < n; j++){
                if(matrix[i][j] < matrix[i][mini_idx])mini_idx = j;
            }
            Row[i] = mini_idx;
        }  
        for(int j = 0; j < n; j++){
            int maxi_idx = 0;
            for(int i = 1; i < m; i++){
                if(matrix[i][j] > matrix[maxi_idx][j])maxi_idx = i;
            }
            Col[j] = maxi_idx;
        } 
        for(int i = 0; i < m; i++){
            if(Row[i] < n && Col[Row[i]] == i)Ans.push_back(matrix[i][Row[i]]);
        } 
        return Ans;   
    }
};