int countSubarrays(int* nums, int numsSize) {
    int cnt = 0;
    for(int i = 0; i < numsSize - 2; i++){
        float frst = nums[i];
        float scnd = nums[i + 1];
        float thrd = nums[i + 2];
        if((frst + thrd) == (scnd / 2.0))cnt++;
    }
    return cnt;
}