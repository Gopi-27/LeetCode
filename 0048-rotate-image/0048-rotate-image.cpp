class Solution {
public:
    void Circulate(int start, vector<vector<int>>& matrix){
        int row = start;
        int col = matrix.size() - 1 - start;
        int cnt = 0;
        while(cnt < (col - row)){
            int nxt = matrix[row + cnt][col];
            int val = matrix[row][row + cnt];
            matrix[row + cnt][col] = val;

            val = nxt;
            nxt = matrix[col][col - cnt];
            matrix[col][col - cnt] = val;

            val = nxt;
            nxt = matrix[col - cnt][row];
            matrix[col - cnt][row] = val;

            val = nxt;
            matrix[row][row + cnt] = val;

            cnt++;
        }
    }
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i = 0; i < n/2; i++)Circulate(i,matrix);
    }
};