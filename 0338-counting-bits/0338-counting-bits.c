/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* countBits(int n, int* returnSize) {
    *returnSize = n + 1;
    int* Ans = (int*)calloc(n + 1,sizeof(int));
    for(int i = 0; i <= n; i++){
        int cnt = 0;
        for(int j = 0; j < 30; j++){
            cnt += (i >> j) & 1;
        }
        Ans[i] = cnt;

    }
    return Ans;


}