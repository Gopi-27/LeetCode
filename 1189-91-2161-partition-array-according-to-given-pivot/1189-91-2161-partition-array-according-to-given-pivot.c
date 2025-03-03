/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* pivotArray(int* nums, int numsSize, int pivot, int* returnSize) {
    *returnSize = numsSize;
    int * Arr=(int *)calloc(numsSize,sizeof(int));
    int lcnt=0;
    int hcnt=0;
    int ecnt=0;
    for(int i=0; i<numsSize; i++){
        if(nums[i]>pivot){
            hcnt++;
        }else if(nums[i]<pivot){
            lcnt++;
        }else{
            ecnt++;
        }
    }
    int lidx=0;
    int eidx=lcnt;
    int hidx=lcnt+ecnt;
    for(int i=0; i<numsSize; i++){
        if(nums[i]<pivot){
            Arr[lidx]=nums[i];
            lidx++;
        }else if(nums[i]>pivot){
            Arr[hidx]=nums[i];
            hidx++;
        }else{
           Arr[eidx]=nums[i];
           eidx++;
        }
    }
    return Arr;

}
