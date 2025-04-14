int Min(int a,int b){
    if(a > b)return b;
    return a;
}
int minimumOperations(int* nums, int numsSize) {
    int Ans = 0;
    for(int i = 0; i < numsSize; i++){
        Ans += Min(nums[i] % 3, 3 - (nums[i] % 3));
    }
    return Ans;
}