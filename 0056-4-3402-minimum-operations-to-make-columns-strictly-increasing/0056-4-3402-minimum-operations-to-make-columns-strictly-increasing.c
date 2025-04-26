int minimumOperations(int** grid, int gridSize, int* gridColSize) {
    int cnt = 0;
    for(int j = 0; j < gridColSize[0]; j++){
        for(int i = 1; i < gridSize; i++){
            if(grid[i - 1][j] >= grid[i][j]){
                cnt += grid[i - 1][j] - grid[i][j] + 1;
                grid[i][j] = grid[i - 1][j] + 1;
            }
        }
    }
    return cnt;
}