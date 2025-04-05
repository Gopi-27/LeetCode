/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sumZero(int n, int* returnSize) {
    int * Ans = (int*)malloc(n * sizeof(int));
    int idx = 0;
    if(n % 2 == 1)Ans[idx++] = 0;
    int val = 1;
    while(idx <= n - 2){
        Ans[idx++] = val;
        Ans[idx++] = -val;
        val++;
    }
    *returnSize = n;
    return Ans;
}