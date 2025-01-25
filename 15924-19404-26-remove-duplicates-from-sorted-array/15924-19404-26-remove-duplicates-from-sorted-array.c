int removeDuplicates(int* nums, int numsSize) {
    int f[202];
    for(int i=0; i<numsSize ; i++){
        f[nums[i]+100]++;
    }
    int indx=0;
    for(int i=0; i<202; i++){
        if(f[i]>0){
            nums[indx]=i-100;
            indx++;
        }
    }
    return indx;
}