bool hasTrailingZeros(int* nums, int numsSize) {
    int cnt = 0;
    for(int i = 0; i < numsSize; i++){
        if(nums[i] % 2 == 0){
            cnt++;
            if(cnt == 2)return true;
        }
    }
    return false;
}