int Min(int a, int b){
    if(a > b)return b;
    else return a;
}
int Max(int a, int b){
    if(a > b)return a;
    else return b;
}
int minMaxGame(int* nums, int numsSize) {
    
    while(numsSize > 1){
        int idx = 0;
        for(int i = 0; i < numsSize; i += 2){
            if((i/2) % 2 == 0){
                nums[idx++] = Min(nums[i],nums[i + 1]);
            }else{
                nums[idx++] = Max(nums[i],nums[i + 1]);
            }
        }
        numsSize /= 2;
    }
    return nums[0];
}