int removeDuplicates(int* nums, int numsSize) {
    if(numsSize <=2 )return numsSize;
    int idx = 2;
    int ptr = 2;
   
    while(ptr < numsSize){
        if(nums[idx - 2] != nums[ptr] && nums[idx - 1] != nums[ptr]){
            nums[idx++] = nums[ptr];
        }else if(nums[ptr] != nums[idx -2]){
            nums[idx++] = nums[ptr];
        }
        ptr++;
    }
    return idx;

}