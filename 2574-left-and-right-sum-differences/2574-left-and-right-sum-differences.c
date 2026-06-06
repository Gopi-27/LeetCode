/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* leftRightDifference(int* nums, int numsSize, int* returnSize) {
    int lsum = 0; 
    int rsum = 0;
    for(int i = 0; i < numsSize; i++){
        rsum += nums[i];
    }
    int* Ans = (int*)malloc(numsSize * sizeof(int));
    for(int i = 0; i < numsSize; i++){
        rsum -= nums[i];
        Ans[i] = abs(lsum - rsum);
        lsum += nums[i];
    }
    *returnSize = numsSize;
    return Ans;

}