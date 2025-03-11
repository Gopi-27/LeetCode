void Merge(int * A,int start,int mid,int end){
    int i = start;
    int j = mid + 1; 
    int k = 0;
    int B[end - start + 1];
    while(i <= mid && j <= end){
        if(A[i] < A[j])B[k++] = A[i++];
        else B[k++] = A[j++];
    }
    while(i <= mid)B[k++] = A[i++];
    while(j <= end)B[k++] = A[j++];
    k = 0;
    for(i = start; i<=end ;i++){
        A[i] = B[k++];
    }
    return ;
}
void MergeSort(int * A,int start,int end){
    if(start >= end)return;
    int mid = (start + end) >> 1;
    MergeSort(A,start,mid);
    MergeSort(A,mid+1,end);
    Merge(A,start,mid,end);
    return ;
}
bool containsDuplicate(int* nums, int numsSize) {
    MergeSort(nums,0,numsSize - 1);
    int flag = 0;
    for(int i = 1; i < numsSize ; i++){
        if(nums[i-1] == nums[i]){
            flag = 1;
            break;
        }
    }
    if(flag == 0)return false;
    else return true ;
    
}








