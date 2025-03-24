void Merge(int** A,int start,int mid, int end){
    int i = start;
    int j = mid + 1;
    int k = 0;
    int B[end - start + 1][2];
    while(i <= mid && j <= end ){
        if(A[i][0] < A[j][0]){
            B[k][0] = A[i][0];
            B[k][1] = A[i][1];
            k++;
            i++;
        }else if (A[i][0] > A[j][0]){
            B[k][0] = A[j][0];
            B[k][1] = A[j][1];
            k++;
            j++;
        }else{
            if(A[i][1] < A[j][1]){
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
    for( i = start; i <= end; i++){
        A[i][0] = B[k][0];
        A[i][1] = B[k][1];
        k++;
    }
    return ;
}
void MergeSort(int** A,int start,int end){
    if(start >= end)return ;
    int mid = (start + end) >> 1;
    MergeSort(A, start, mid);
    MergeSort(A, mid + 1, end);
    Merge(A, start, mid, end);
    return ;
}
int countDays(int days, int** meetings, int meetingsSize, int* meetingsColSize) {
    MergeSort(meetings , 0 , meetingsSize - 1);
    int ans = 0;
    int lmin = meetings[0][0];
    int rmax = meetings[0][1];
    int fdays = lmin - 0 - 1;
    if(fdays > 0)ans +=fdays;
    lmin = 0;
    for(int i = 0; i < meetingsSize; i++){
        if(meetings[i][0] >= lmin  && meetings[i][0] <= rmax && meetings[i][1] > rmax){
            rmax = meetings[i][1];
        }else if(meetings[i][0] > rmax){
            fdays = meetings[i][0] - rmax - 1;
            if(fdays > 0)ans += fdays;
            rmax = meetings[i][1];
        }
        
    }
    fdays = days - rmax;
    if(fdays > 0) ans +=fdays;
    return ans;

}