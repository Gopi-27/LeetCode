/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int GetCnt(int a){
    int cnt = 0;
    while(a > 0){
        if((a & 1) == 1)cnt++;
        a = a >> 1;
    }
    return cnt;
}
void Merge(int* arr,int* crr,int start,int mid,int end){
    int A[end - start + 1];
    int C[end - start + 1];
    int i = start;
    int j = mid + 1;
    int k = 0;
    while(i <= mid && j <= end){
        if(crr[i] > crr[j]){
            C[k] = crr[j];
            A[k] = arr[j];
            k++;
            j++;
        }else if(crr[i] < crr[j]){
            C[k] = crr[i];
            A[k] = arr[i];
            i++;
            k++;
        }else{
            if(arr[i] > arr[j]){
                C[k] = crr[j];
                A[k] = arr[j];
                k++;
                j++;
            }else{
                C[k] = crr[i];
                A[k] = arr[i];
                i++;
                k++;
            }
        }
    }
    while(i <= mid){
        C[k] = crr[i];
        A[k] = arr[i];
        i++;
        k++;
    }
    while(j <= end){
        C[k] = crr[j];
        A[k] = arr[j];
        k++;
        j++;    
    }
    i = 0;
    k = 0;
    for(int i = start; i <= end; i++){
        arr[i] = A[k];
        crr[i] = C[k];
        k++;
    }
    return ;
}
void MergeSort(int* arr,int* crr,int start,int end){
    if(start >= end)return;
    int mid = (start + end) >> 1;
    MergeSort(arr,crr,start,mid);
    MergeSort(arr,crr,mid + 1,end);
    Merge(arr,crr,start,mid,end);
    return ;
}
int* sortByBits(int* arr, int arrSize, int* returnSize) {
    int* crr = (int*)calloc(arrSize,sizeof(int));
    for(int i = 0; i < arrSize; i++){
        crr[i] = GetCnt(arr[i]);
    }
    MergeSort(arr,crr,0,arrSize - 1);
    free(crr);
    *returnSize = arrSize;
    return arr;
}