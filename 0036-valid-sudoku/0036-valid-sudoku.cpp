class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < 9; i++){
            vector<bool>row(9),col(9);
            for(int j = 0; j < 9; j++){
                if(board[i][j] != '.'){
                    if(row[board[i][j] - '1'])return false;
                    else row[board[i][j] - '1'] = 1;
                }
                if(board[j][i] != '.'){
                    if(col[board[j][i] - '1'])return false;
                    else col[board[j][i] - '1'] = 1;
                }
            }
        }

        for(int row = 0; row < 9; row += 3){
            for(int col = 0; col < 9; col += 3){
                vector<bool>freq(9);
                for(int i = row; i < row + 3; i++){
                    for(int j = col; j < col + 3; j++){
                        if(board[i][j] != '.'){
                            if(freq[board[i][j] - '1'])return false;
                            else freq[board[i][j] - '1'] = 1;
                        }
                    }
                }
            }
        }
        return true;
    }
};