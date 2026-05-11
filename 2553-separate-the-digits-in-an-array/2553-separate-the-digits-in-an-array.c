/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* separateDigits(int* nums, int numsSize, int* returnSize) {
    int n=0;
    for(int i=0; i<numsSize; i++){
        n+=log10(nums[i])+1;
    }
    *returnSize=n;
    int * arr=(int *)malloc(n*sizeof(int));
    int j=n-1;
    for(int i=numsSize-1; i>=0; i--){
        while(nums[i]>0){
            arr[j]=nums[i]%10;
            j--;
            nums[i]/=10;
        }
    }

    return arr;
}