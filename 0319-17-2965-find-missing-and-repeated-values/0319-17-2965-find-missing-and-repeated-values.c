/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findMissingAndRepeatedValues(int** grid, int gridSize, int* gridColSize, int* returnSize) {
    *returnSize = 2;
    int len = (gridSize * gridSize) + 1;
    int * frr = (int *)calloc(len , sizeof(int));
    for(int i = 0; i < gridSize; i++){
        for(int j = 0; j < gridSize; j++){
            frr[grid[i][j]]++;
        }
    }
    int * ans = (int *) malloc (2 * sizeof(int));
    for(int i = 1; i < len; i++){
        if(frr[i]==2)ans[0] = i;

        if(frr[i]==0)ans[1] = i;
    }
    free(frr);
    return ans;
}