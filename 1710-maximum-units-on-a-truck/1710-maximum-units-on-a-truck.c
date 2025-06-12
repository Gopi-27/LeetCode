void Merge(int** A,int start,int mid,int end){
    int i = start;
    int j = mid + 1;
    int k = 0;
    int B[end - start + 1][2];
    while(i <= mid && j <= end){
        if(A[i][1] > A[j][1]){
            B[k][0] = A[i][0];
            B[k][1] = A[i][1];
            k++;
            i++;
        }else{
            B[k][0] = A[j][0];
            B[k][1] = A[j][1];
            k++;
            j++;
        }
    }
    while(i <= mid){
        B[k][0] = A[i][0];
        B[k][1] = A[i][1];
        k++;
        i++;
    }
    while(j <= end){
        B[k][0] = A[j][0];
        B[k][1] = A[j][1];
        k++;
        j++; 
    }
    k = 0;
    for(i = start; i <= end; i++){
        A[i][0] = B[k][0];
        A[i][1] = B[k][1];
        k++;
    }
    return ;
}
void MergeSort(int** A,int start,int end){
    if(start >= end)return ;
    int mid = (start + end) >> 1;
    MergeSort(A,start,mid);
    MergeSort(A,mid + 1,end);
    Merge(A,start,mid,end);
    return;
}
int maximumUnits(int** boxTypes, int boxTypesSize, int* boxTypesColSize, int truckSize) {
    MergeSort(boxTypes,0,boxTypesSize - 1);
    int box_cnt = 0;
    int ans = 0;
    int i = 0;
    while(i < boxTypesSize  && box_cnt + boxTypes[i][0] <= truckSize){
        box_cnt += boxTypes[i][0];
        ans += boxTypes[i][0] * boxTypes[i][1];
        i++;
    }
    if(i < boxTypesSize  && box_cnt < truckSize ){
        ans += (truckSize - box_cnt) * boxTypes[i][1];
    }
    return ans;
}