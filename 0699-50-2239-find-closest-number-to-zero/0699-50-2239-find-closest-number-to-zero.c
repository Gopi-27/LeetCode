int ABS(int n){
    if(n>=0)return n;
    else return -n;
}

int findClosestNumber(int* nums, int numsSize) {
    int min_dis=ABS(nums[0]);
    int ele=nums[0];
    for(int i=1; i<numsSize; i++){
        if(min_dis>ABS(nums[i])){
            min_dis=ABS(nums[i]);
            ele=nums[i];
        }else if(min_dis==ABS(nums[i])){
            if(ele<nums[i]){
                ele=nums[i];
            }
        }
    }
    return ele;
}