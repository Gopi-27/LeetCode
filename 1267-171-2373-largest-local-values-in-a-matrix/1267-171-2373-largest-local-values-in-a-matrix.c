

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
 int GetMax(int** grid,int i,int j){
    int max = grid[i][j];
    for(int r = i - 1; r <= i + 1; r++){
        for(int c = j - 1; c <= j + 1; c++){
            if(grid[r][c] > max)max = grid[r][c];
        }
    }
    return max;
 }
int** largestLocal(int** grid, int gridSize, int* gridColSize, int* returnSize, int** returnColumnSizes) {
    *returnSize = gridSize - 2;
    *returnColumnSizes = (int*)calloc(gridSize - 2,sizeof(int));
    for(int i = 0; i < gridSize - 2; i++){
        (*returnColumnSizes)[i] = gridSize - 2;
    }
    int** Ans = (int**)calloc(gridSize - 2,sizeof(int*));
    for(int i = 0; i < gridSize - 2; i++){
        Ans[i] = (int*)calloc(gridSize - 2,sizeof(int));
    }
    for(int i = 0; i < gridSize - 2; i++){
        for(int j = 0; j < gridSize - 2; j++){
            Ans[i][j] = GetMax(grid,i + 1,j + 1);
        }
    }
    return Ans;
}