void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    for(int i=0; i<n; i++){
        // inserting the second array elements in the first array
        nums1[m+i]=nums2[i];
    }
    // sorting the array (Using Bubble sort)
    for(int i=0; i<m+n-1; i++){
        for(int j=1; j<m+n-i; j++){
            if(nums1[j-1]>nums1[j]){
                // swapping the elements
                int temp=nums1[j-1];
                nums1[j-1]=nums1[j];
                nums1[j]=temp;
            }
        }
    }


}
