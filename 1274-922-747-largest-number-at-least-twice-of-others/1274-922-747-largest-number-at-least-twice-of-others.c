int dominantIndex(int* nums, int numsSize) {
    int maxidx = 0;
    for(int i = 1; i < numsSize; i++){
        if(nums[maxidx] < nums[i])maxidx = i;
    }
    for(int i = 0; i < numsSize; i++){
        if(i != maxidx && (2 * nums[i]) > nums[maxidx])return -1;
    }
    return maxidx;
}