class Solution {
public:
    bool isValid(vector<string>& Board,int i,int j){
        for(int r = i - 1; r >= 0; r--)if(Board[r][j] == 'Q')return false;
        for(int r = i - 1,c = j + 1; r >= 0 && c < Board.size(); c++,r--)if(Board[r][c] == 'Q')return false;
        for(int r = i - 1,c = j - 1; r >= 0 && c >= 0; c--,r--)if(Board[r][c] == 'Q')return false;
        return true;
    }
    void rec(int i,vector<string>& Board,vector<vector<string>>& Ans){
        if(i == Board.size()){
            Ans.push_back(Board);
            return;
        }
        for(int j = 0; j < Board.size(); j++){
            if(isValid(Board,i,j)){
                Board[i][j] = 'Q';
                rec(i + 1,Board,Ans);
                Board[i][j] = '.';
            }
        }
        return;
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>Ans;
        string temp = "";
        for(int i = 0; i < n; i++)temp += '.';
        vector<string>Board(n,temp);
        rec(0,Board,Ans);
        return Ans;
    }
};