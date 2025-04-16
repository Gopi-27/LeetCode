int Max(int a,int b){
    if(a > b)return a;
    return b;
}
int subarraySum(int* nums, int numsSize) {
    int Ans = 0;
    for(int i = 0; i < numsSize; i++){
        int sum = 0;
        for(int j = Max(0,i - nums[i]); j <= i; j++){
            sum += nums[j];
        }
        Ans += sum;
    }
    return Ans;
}