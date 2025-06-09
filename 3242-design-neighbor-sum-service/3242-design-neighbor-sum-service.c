


typedef struct {
    int** arr;
    int rows ;
    int* cols;
} NeighborSum;


NeighborSum* neighborSumCreate(int** grid, int gridSize, int* gridColSize) {
    NeighborSum* obj = (NeighborSum*)malloc(sizeof(NeighborSum));
    obj->arr = grid;
    obj->rows = gridSize;
    return obj; 
}

int neighborSumAdjacentSum(NeighborSum* obj, int value) {
    int sum = 0;
    for(int i = 0; i < obj->rows; i++){
        for(int j = 0; j < obj->rows; j++){
            if(obj->arr[i][j] == value){
                if(i - 1 >= 0)sum += obj->arr[i - 1][j];
                if(i + 1 < obj->rows)sum += obj->arr[i + 1][j];
                if(j - 1 >= 0)sum += obj->arr[i][j - 1];
                if(j + 1 < obj->rows)sum += obj->arr[i][j + 1];
                return sum;
            }
        }
    }
    // never come
    return 0;
}

int neighborSumDiagonalSum(NeighborSum* obj, int value) {
    int sum = 0;
    for(int i = 0; i < obj->rows; i++){
        for(int j = 0; j < obj->rows; j++){
            if(obj->arr[i][j] == value){
                if(i - 1 >= 0 && j - 1 >= 0)sum += obj->arr[i - 1][j - 1];
                if(i - 1 >= 0 && j + 1 < obj->rows)sum += obj->arr[i - 1][j + 1];
                if(i + 1 < obj->rows && j - 1 >= 0)sum += obj->arr[i + 1][j - 1];
                if(i + 1 < obj->rows && j + 1 < obj->rows)sum += obj->arr[i +1][j + 1];
                return sum;
            }
        }
    }
    // never come
    return 0;
}

void neighborSumFree(NeighborSum* obj) {
    free(obj);
}

/**
 * Your NeighborSum struct will be instantiated and called as such:
 * NeighborSum* obj = neighborSumCreate(grid, gridSize, gridColSize);
 * int param_1 = neighborSumAdjacentSum(obj, value);
 
 * int param_2 = neighborSumDiagonalSum(obj, value);
 
 * neighborSumFree(obj);
*/