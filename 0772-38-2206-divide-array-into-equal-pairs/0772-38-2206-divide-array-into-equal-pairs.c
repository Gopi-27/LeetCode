bool divideArray(int* nums, int numsSize) {
    int frr[501] = {0};
    for(int i = 0; i < numsSize; i++){
        frr[nums[i]]++;
    }
    for(int i = 0; i < 501; i++){
        if(frr[i] % 2 == 1)return false;
    }
    return true;
}