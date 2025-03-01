/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* transformArray(int* nums, int numsSize, int* returnSize) {
    *returnSize=numsSize;
    int *arr=(int *)calloc(numsSize,sizeof(int));
    int fidx=0;
    int lidx=numsSize-1;
    for(int i=0; i<numsSize; i++){
        if(nums[i]%2==0){
            arr[fidx++]=0;
        }else{
            arr[lidx--]=1;
        }
    }
    return arr;
}