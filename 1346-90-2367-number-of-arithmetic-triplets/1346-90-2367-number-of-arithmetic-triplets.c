int arithmeticTriplets(int* nums, int numsSize, int dif) {
    int cnt = 0;
    for(int i = 0; i < numsSize - 2; i++){
        for(int j = i + 1; j < numsSize - 1; j++){
            if(nums[j] - nums[i] == dif){
                for(int k = j + 1; k < numsSize; k++){
                    if(nums[k] - nums[j] == dif)cnt++;
                    else if(nums[k] - nums[j] > dif)break;
                }
            }else if(nums[j] - nums[i] > dif){
                break;
            }
        }
    }
    return cnt;
}