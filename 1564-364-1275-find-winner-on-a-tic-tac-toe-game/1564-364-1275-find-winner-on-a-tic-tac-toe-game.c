char* tictactoe(int** moves, int movesSize, int* movesColSize) {
    int Board[3][3];
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++ ){
            Board[i][j] = 0;
        }
    }
    for(int i = 0; i < movesSize; i++){
        if(i % 2 == 0){
            Board[moves[i][0]][moves[i][1]] = 1;
        }else{
            Board[moves[i][0]][moves[i][1]] = 2;
        }
    }
    if(Board[0][0] == 1 && Board[0][1] == 1 && Board[0][2] == 1)return "A";
    if(Board[1][0] == 1 && Board[1][1] == 1 && Board[1][2] == 1)return "A";
    if(Board[2][0] == 1 && Board[2][1] == 1 && Board[2][2] == 1)return "A";
    if(Board[0][0] == 1 && Board[1][0] == 1 && Board[2][0] == 1)return "A";
    if(Board[0][1] == 1 && Board[1][1] == 1 && Board[2][1] == 1)return "A";
    if(Board[0][2] == 1 && Board[1][2] == 1 && Board[2][2] == 1)return "A";
    if(Board[0][0] == 1 && Board[1][1] == 1 && Board[2][2] == 1)return "A";
    if(Board[0][2] == 1 && Board[1][1] == 1 && Board[2][0] == 1)return "A";
    
    if(Board[0][0] == 2 && Board[0][1] == 2 && Board[0][2] == 2)return "B";
    if(Board[1][0] == 2 && Board[1][1] == 2 && Board[1][2] == 2)return "B";
    if(Board[2][0] == 2 && Board[2][1] == 2 && Board[2][2] == 2)return "B";
    if(Board[0][0] == 2 && Board[1][0] == 2 && Board[2][0] == 2)return "B";
    if(Board[0][1] == 2 && Board[1][1] == 2 && Board[2][1] == 2)return "B";
    if(Board[0][2] == 2 && Board[1][2] == 2 && Board[2][2] == 2)return "B";
    if(Board[0][0] == 2 && Board[1][1] == 2 && Board[2][2] == 2)return "B";
    if(Board[0][2] == 2 && Board[1][1] == 2 && Board[2][0] == 2)return "B";

    if(movesSize == 9)return "Draw";
    return "Pending";
    


}