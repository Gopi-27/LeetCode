int singleNumber(int* nums, int numsSize) {
    int posfrr[30001]={0};
    int negfrr[30001]={0};
    for(int i=0; i<numsSize; i++){
        if(nums[i]>=0){
            posfrr[nums[i]]++;
        }else{
            negfrr[(-1)*(nums[i])]++;
        }
    }
    int ans;
    for(int i=0; i<30001;i++){
        if(posfrr[i]==1){
            ans=i;
            break;
        }
    }
    
    for(int i=0; i<30001; i++){
        if(negfrr[i]==1){
            ans=(-i);
            break;
        }
    }
    return ans;
}