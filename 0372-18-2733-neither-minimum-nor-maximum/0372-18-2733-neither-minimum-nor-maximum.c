int findNonMinOrMax(int* nums, int numsSize) {
    if(numsSize <= 2) return -1;
    int min_idx = 0;
    int max_idx = 0;
    for(int i = 1; i < numsSize; i++){
        if(nums[min_idx] > nums[i])min_idx = i;
        if(nums[max_idx] < nums[i])max_idx = i;
    }
    int ans;
    for(int i = 0; i < numsSize; i++){
        if(nums[i] != nums[min_idx] && nums[i] != nums[max_idx]){
            ans = nums[i];
            break;
        }

    }
    return ans;
    
}