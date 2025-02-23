int addedInteger(int* nums1, int nums1Size, int* nums2, int nums2Size) {

    int min1=nums1[0];
    int min2=nums2[0];
    for(int i=1; i<nums1Size; i++){
        if(min1>nums1[i]){
            min1=nums1[i];
        }
        if(min2>nums2[i]){
            min2=nums2[i];
        }
    }
    return min2-min1;
    
}