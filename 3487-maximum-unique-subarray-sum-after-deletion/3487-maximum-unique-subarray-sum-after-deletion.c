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
void MergeSort(int* A,int start,int end){
    if(start >= end)return;
    int mid = (start + end) >> 1;
    MergeSort(A,start,mid);
    MergeSort(A,mid + 1,end);
    Merge(A,start,mid,end);
    return;
}
int maxSum(int* nums, int n) {
    MergeSort(nums,0,n - 1);
    if(nums[n - 1] <= 0)return nums[n - 1];
    int i = 0;
    while(i < n && nums[i] <= 0)i++;
    int sum = 0;
    while(i < n){
        sum += nums[i];
        i++;
        while(i < n && nums[i] == nums[i - 1])i++;
    }
    return sum;
}