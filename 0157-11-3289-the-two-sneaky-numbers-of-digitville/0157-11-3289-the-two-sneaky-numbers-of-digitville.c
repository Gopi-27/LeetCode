/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getSneakyNumbers(int* nums, int numsSize, int* returnSize) {
    *returnSize = 2;
    int* Ans = (int*)malloc(2 * sizeof(int));
    int frr[100] = {0};
    for(int i = 0; i < numsSize; i++){
        frr[nums[i]]++;
    }
    int idx = 0;
    for(int i = 0; i < 100; i++){
        if(idx == 2)break;
        if(frr[i] == 2){
            Ans[idx++] = i;
        }
    }
    return Ans;
}