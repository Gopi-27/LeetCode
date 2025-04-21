bool isArraySpecial(int* nums, int numsSize) {
    int rem = nums[0] % 2;
    for(int i = 2; i < numsSize; i += 2){
        if(nums[i] % 2 != rem)return false;
    }
    for(int i = 1; i < numsSize; i += 2){
        if(nums[i] % 2 == rem)return false;
    }
    return true;
}