/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
 void Merge(int** A,int start,int mid, int end){
    int i = start;
    int j = mid + 1;
    int k = 0;
    int B[end - start + 1][2];
    while(i <= mid && j <= end){
        if(A[i][0] > A[j][0]){
            B[k][0] = A[j][0];
            B[k][1] = A[j][1];
            k++;
            j++;
        }else if(A[i][0] < A[j][0]){
            B[k][0] = A[i][0];
            B[k][1] = A[i][1];
            k++;
            i++;
        }else{
            if(A[i][1] > A[j][1]){
                B[k][0] = A[j][0];
                B[k][1] = A[j][1];
                k++;
                j++;
            }else{
                B[k][0] = A[i][0];
                B[k][1] = A[i][1];
                i++;
                k++;
            }
        }
    }
    while(i <= mid){
        B[k][0] = A[i][0];
        B[k][1] = A[i][1]; 
        i++;
        k++;
    }
    while(j <= end){
        B[k][0] = A[j][0];
        B[k][1] = A[j][1];
        j++;
        k++;
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
    MergeSort(A,mid + 1, end);
    Merge(A,start,mid,end);
    return ;
}


int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes) {
    MergeSort(intervals,0,intervalsSize - 1);
    int idx = 0;
    for(int i = 1; i < intervalsSize; i++){
        if(intervals[idx][1] >= intervals[i][0] && intervals[idx][1] < intervals[i][1]){
            intervals[idx][1] = intervals[i][1];
        }else if(intervals[idx][1] < intervals[i][0]){
            idx++;
            intervals[idx][0] = intervals[i][0];
            intervals[idx][1] = intervals[i][1];
        }
    }
    *returnSize = idx + 1;
    *returnColumnSizes = (int *)calloc(idx + 1, sizeof(int));
    for(int i = 0; i < idx + 1; i++)(*returnColumnSizes)[i] = 2;
    return intervals;    
}