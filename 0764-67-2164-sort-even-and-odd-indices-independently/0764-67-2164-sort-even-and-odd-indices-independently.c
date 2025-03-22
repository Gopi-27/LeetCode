/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 
int* sortEvenOdd(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    for(int i = 0; i < numsSize; i++){
        int flag = 0;
        for(int j = 2; j < numsSize; j += 2){
            if(nums[j - 2] > nums[j]){
                int temp = nums[j - 2];
                nums[j - 2] = nums[j];
                nums[j] = temp;
                flag = 1;
            }
        }
        if(flag == 0)break;
    }
    for(int i = 0; i < numsSize; i++){
        int flag = 0;
        for(int j = 3; j < numsSize; j += 2){
            if(nums[j - 2] < nums[j]){
                int temp = nums[j - 2];
                nums[j - 2] = nums[j];
                nums[j] = temp;
                flag = 1;
            }
        }
        if(flag == 0)break;
    }
    return nums;
}