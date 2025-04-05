int diagonalSum(int** mat, int matSize, int* matColSize) {
    int sum = 0;
    int i = 0;
    while(i < matSize)sum += mat[i][i++];
    i = 0;
    int j = matSize - 1;
    while(j >= 0){
        sum += mat[i][j];
        i++;
        j--;
    }
    if(matSize % 2 == 1)sum -= mat[matSize/2][matSize/2];
    return sum;

}