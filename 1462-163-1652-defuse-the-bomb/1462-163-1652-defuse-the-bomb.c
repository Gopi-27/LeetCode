/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* decrypt(int* code, int n, int k, int* returnSize) {
    *returnSize = n;
    int* ans = (int*)calloc(n,sizeof(int));
    if(k == 0)return ans;
    if(k > 0){
        // 5,7,1,4    k = 3
        int left = 1;
        int right = k;
        int sum = 0;
        for(int i = left; i <= right; i++)sum += code[i];
        int i = 1;
        ans[0] = sum;
        while(i < n){
            left = left % n;
            right = (right + 1) % n;
            sum -= code[left++];
            sum += code[right];
            ans[i++] = sum;
        }
        return ans;
    }
    int left = n + k;
    int right = n - 1;
    int sum = 0;
    for(int i = left; i <= right; i++)sum += code[i];
    int i = 1;
    ans[0] = sum;
    while(i < n){
        left = left % n;
        right = (right + 1) % n;
        sum -= code[left++];
        sum += code[right];
        ans[i++] = sum;
    }
    return ans;
}