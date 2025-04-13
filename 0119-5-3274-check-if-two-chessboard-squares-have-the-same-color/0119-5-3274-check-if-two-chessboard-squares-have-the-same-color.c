char GetColor(int x, int y){
    // same parity black color
    // opposite parity white color
    if((x % 2 == 0 && y % 2 == 0) || (x % 2 == 1 && y % 2 == 1))return 'B';
    else return 'W';
}

bool checkTwoChessboards(char* coordinate1, char* coordinate2) {
    int x1 = (coordinate1[0] - 'a') + 1;
    int y1 = coordinate1[1] - '0';
    int x2 = (coordinate2[0] - 'a') + 1;
    int y2 = coordinate2[1] - '0';
    char fcol = GetColor(x1,y1);
    char scol = GetColor(x2,y2);
    if(fcol == scol)return true;
    return false;

    



}