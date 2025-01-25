int removeElement(int* nums, int numsSize, int val) {
    int cnt=0;
    for(int i=0; i<numsSize; i++){
        if(nums[i]==val){
            nums[i]=55;
            cnt++;
        }
    }
    for(int i=0; i<numsSize-1; i++){
        for(int j=0; j<numsSize-i-1; j++){
            if(nums[j]>nums[j+1]){
                int temp=nums[j];
                nums[j]=nums[j+1];
                nums[j+1]=temp;
            }
        }
    }
    return numsSize-cnt;
    
    
}