double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int arr[nums1Size+nums2Size];
    int ind=0;
    for(int i=0; i<nums1Size; i++){
        arr[ind]=nums1[i];
        ind++;
    }
    for(int i=0; i<nums2Size; i++){
        arr[ind]=nums2[i];
        ind++;
    }
    for(int i=0; i<nums1Size+nums2Size-1; i++){
        for(int j=0; j<nums1Size+nums2Size-i-1; j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    double med=0;
 if((nums1Size+nums2Size)%2==0){
    med=(arr[(nums1Size+nums2Size)/2]+arr[((nums1Size+nums2Size)/2)-1])/2.0;
 }else{
   med=arr[(nums1Size+nums2Size-1)/2]; 
 }
 return med;
}