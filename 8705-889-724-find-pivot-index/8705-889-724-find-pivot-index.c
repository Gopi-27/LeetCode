int pivotIndex(int* nums, int numsSize) {
    if(numsSize <= 1)return 0;
    int lsum = 0;
    int rsum = 0;
    for(int i = 1; i < numsSize; i++)rsum += nums[i];
    int left = -1;
    int right = 1;
    while(lsum != rsum && right < numsSize){
        lsum += nums[++left];
        rsum -= nums[right++];
    }
    if(lsum == rsum)return left + 1;
    return -1;
}