int Min(int a, int b){
    if(a > b)return b;
    else return a;
}
int getMinDistance(int* nums, int numsSize, int target, int start) {
    int left = -1;
    int right = -1;
    for(int i = start; i >= 0; i--){
        if(nums[i] == target){
            left = i;
            break;
        }
    }
    for(int i = start + 1; i < numsSize; i++){
        if(nums[i] == target){
            right = i;
            break;
        }
    }
    if(left != -1 && right != -1)return Min(start - left , right - start);
    else if(left == -1)return right - start;
    else return start - left;
}