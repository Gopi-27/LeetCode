/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* decode(int* encoded, int encodedSize, int first, int* returnSize) {
    *returnSize = encodedSize + 1;
    int* Ans = (int*)calloc(encodedSize + 1,sizeof(int));
    Ans[0] = first;
    for(int i = 0; i < encodedSize; i++){
        Ans[i + 1] = (encoded[i] ^ Ans[i]);
    }
    return Ans;

}