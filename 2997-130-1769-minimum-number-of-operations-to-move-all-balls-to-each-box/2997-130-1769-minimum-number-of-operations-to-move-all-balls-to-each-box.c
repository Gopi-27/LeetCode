/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* minOperations(char* boxes, int* returnSize) {
    int len = strlen(boxes);
    *returnSize = len;
    int* Ans = (int*)calloc(len,sizeof(int));
    for(int i = 0; i < len; i++){
        if(boxes[i] == '1'){
            for(int j = 0; j < len; j++){
                Ans[j] += abs(i - j);
            }
        }
    }
    return Ans;
}