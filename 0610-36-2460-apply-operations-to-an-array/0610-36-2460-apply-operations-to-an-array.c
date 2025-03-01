/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* applyOperations(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    int* arr = (int *)calloc(numsSize,sizeof(int));
    int lidx=numsSize-1;
    int fidx=0;
    for(int i=0; i<numsSize-1; i++){
        if(nums[i]==nums[i+1]){
            nums[i]=2*nums[i];
            nums[i+1]=0;
        }
        if(nums[i]==0){
            arr[lidx--]=0;
        }else{
            arr[fidx++]=nums[i];
        }
    }
    if(nums[numsSize-1]==0){
        arr[lidx--]=nums[numsSize-1];
    }else{
        arr[fidx++]=nums[numsSize-1];
    }
    return arr;
}