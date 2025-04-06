int maximumDifference(int* nums, int numsSize) {
    int Ans = -1;
    int stack[numsSize];
    int Top = 0;
    stack[Top] = nums[numsSize - 1];
    for(int i = numsSize - 2; i >= 0; i--){
        if(stack[Top] > nums[i]){
            if(Ans < (stack[Top] - nums[i])){
                Ans = stack[Top] - nums[i];
            }
        }else{
            Top++;
            stack[Top] = nums[i];
        }
    }
    return Ans;

}