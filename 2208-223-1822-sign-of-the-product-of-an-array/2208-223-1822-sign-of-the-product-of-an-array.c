int arraySign(int* nums, int numsSize) {
    int pro=1;

    for(int i=0; i<numsSize; i++){
        if((pro*nums[i])>0){
            pro=1;
        }else if((pro*nums[i])<0){
            pro=-1;
        }else{
            pro=0;
        }

    }
    return pro;
}