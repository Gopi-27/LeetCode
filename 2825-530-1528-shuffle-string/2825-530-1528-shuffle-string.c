void Merge(char* str,int* A,int start,int mid,int end){
    int i = start;
    int j = mid + 1;
    int k = 0;
    int B[end - start + 1];
    char str1[end - start + 2];
   // str1[end - start + 1] = '\0';
    while(i <= mid && j <= end){
        if(A[i] < A[j]){
            B[k] = A[i];
            str1[k] = str[i];
            k++;
            i++;
        }else{
             B[k] = A[j];
             str1[k] = str[j];
             k++;
             j++;
        }
    }
    while(i <= mid){
        B[k] = A[i];
        str1[k] = str[i];
        i++;
        k++;
    }
    while(j <= end){
        B[k] = A[j];
        str1[k] = str[j];
        k++;
        j++;
    }
    k = 0;
    for(i = start; i <= end; i++){
        A[i] = B[k];
        str[i] = str1[k];
        k++;
    }
    return ;
}

void MergeSort(char* str,int* A,int start,int end){
    if(start >= end)return ;
    int mid = (start + end) / 2;
    MergeSort(str,A,start,mid);
    MergeSort(str,A,mid+1,end);
    Merge(str,A,start,mid,end);
    return ;
}
char* restoreString(char* s, int* indices, int indicesSize) {
   MergeSort(s,indices,0,indicesSize-1);
   return s; 
}