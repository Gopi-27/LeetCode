/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 void Merge(int* A,int start,int mid,int end,char **names){
    int i = start;
    int j = mid + 1;
    int B[end - start + 1];
    int k = 0;
    char N[end - start + 1][22];
    while(i <= mid && j <= end){
        if(A[i] > A[j]){
            B[k] = A[i];
            strcpy(N[k],names[i]);
            k++;
            i++;
        }else{
            B[k] = A[j];
            strcpy(N[k],names[j]);
            k++;
            j++;
        }
    }
    while(i <= mid){
        B[k] = A[i];
        strcpy(N[k],names[i]);
        k++;
        i++;
    }
    while(j <= end){
        B[k] = A[j];
        strcpy(N[k],names[j]);
        k++;
        j++;
    }
    k = 0;
    for(i = start; i <= end; i++){
        A[i] = B[k];
        strcpy(names[i],N[k]);
        k++;
    }
    return;
 }
 void MergeSort(int* A,int start,int end,char** names){
    if(start >= end)return ;
    int mid = (start + end) >> 1;
    MergeSort(A,start,mid,names);
    MergeSort(A,mid + 1, end,names);
    Merge(A,start,mid,end,names);
    return ;
 }
char** sortPeople(char** names, int namesSize, int* heights, int heightsSize, int* returnSize) {
    *returnSize = namesSize;
    for(int i = 0 ; i < namesSize; i++){
        names[i] = (char *)realloc(names[i],22*sizeof(char*));
    }
    MergeSort(heights,0,heightsSize - 1,names);
    return names;
}