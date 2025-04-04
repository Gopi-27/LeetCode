/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getConcatenation(int* nums, int numsSize, int* returnSize) {
    *returnSize = 2 * numsSize;
    nums = (int *)realloc(nums,2 * numsSize * sizeof(int));
    for(int i = 0; i < numsSize; i++){
        nums[i + numsSize] = nums[i];
    }
    return nums;
}