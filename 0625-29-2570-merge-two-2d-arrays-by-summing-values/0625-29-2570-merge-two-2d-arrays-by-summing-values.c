/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** mergeArrays(int** nums1, int nums1Size, int* nums1ColSize, int** nums2, int nums2Size, int* nums2ColSize, int* returnSize, int** returnColumnSizes) {
    int i=0;
    int j=0;
    int k=0;
    int **Arr=(int **)malloc(k*sizeof(int*));
    while(i<nums1Size && j<nums2Size){
        if(nums1[i][0]<nums2[j][0]){
            k++;
            Arr=(int **)realloc(Arr,k*sizeof(int*));
            Arr[k-1]=(int *)malloc(2*sizeof(int));
            Arr[k-1][0]=nums1[i][0];
            Arr[k-1][1]=nums1[i][1];
            i++;
            

        }else if(nums1[i][0]>nums2[j][0]){
            k++;
            Arr=(int **)realloc(Arr,k*sizeof(int*));
            Arr[k-1]=(int *)malloc(2*sizeof(int));
            Arr[k-1][0]=nums2[j][0];
            Arr[k-1][1]=nums2[j][1];
           // Add_To_Array(j);
            j++;
        
        }else{
             k++;
            Arr=(int **)realloc(Arr,k*sizeof(int*));
            Arr[k-1]=(int *)malloc(2*sizeof(int));
            Arr[k-1][0]=nums1[i][0];
            Arr[k-1][1]=nums1[i][1]+nums2[j][1];
           // Add_To_Array(i+j);
            i++;
            j++;
          
        }
      //  returnColumnSizes[k-1]=2;
    }
    while(i<nums1Size){
        k++;
        Arr=(int **)realloc(Arr,k*sizeof(int*));
        Arr[k-1]=(int *)malloc(2*sizeof(int));
        Arr[k-1][0]=nums1[i][0];
        Arr[k-1][1]=nums1[i][1];
        //Add_To_Array(i);
        i++;
       // returnColumnSizes[k-1]=2;
    }
    while(j<nums2Size){
        k++;
        Arr=(int **)realloc(Arr,k*sizeof(int*));
        Arr[k-1]=(int *)malloc(2*sizeof(int));
        Arr[k-1][0]=nums2[j][0];
        Arr[k-1][1]=nums2[j][1];
       // Add_To_Array(j);
        j++;
       // returnColumnSizes[k-1]=2;
    }
    *returnSize=k;
    *returnColumnSizes=(int *)malloc(k*sizeof(int));
    for(int i=0; i<k; i++){
        (*returnColumnSizes)[i]=2;
    }
    return Arr;
}