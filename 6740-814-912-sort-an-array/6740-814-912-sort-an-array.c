/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

void Merge(int* A,int start,int mid,int end){
    int i = start;
    int j = mid + 1;
    int k = 0;
    int B[end - start + 1];
    while(i <= mid && j <= end){
        if(A[i] > A[j])B[k++] = A[j++];
        else B[k++] = A[i++];
    }
    while(i <= mid)B[k++] = A[i++];
    while(j <= end)B[k++] = A[j++];
    k = 0;
    for(i = start; i <= end; i++){
        A[i] = B[k++];
    }
    return;
}
void MergeSort(int* nums,int start,int end){
    if(start >= end)return ;
    int mid = (start + end) >> 1;
    MergeSort(nums,start,mid);
    MergeSort(nums,mid + 1,end);
    Merge(nums,start,mid,end);
    return ;
}

int* sortArray(int* nums, int numsSize, int* returnSize) {
    MergeSort(nums,0,numsSize - 1);
    *returnSize = numsSize;
    return nums;
}