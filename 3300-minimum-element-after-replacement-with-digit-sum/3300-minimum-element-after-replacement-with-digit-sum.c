int GetSum(int n){
    int sum = 0;
    while(n > 0){
        sum += n % 10;
        n /= 10;
    }
    return sum;
}
int minElement(int* nums, int numsSize) {
    int minsum = 9999;
    for(int i = 0; i < numsSize; i++){
        int sum = GetSum(nums[i]);
        if(minsum > sum)minsum = sum;
    }
    return minsum;
}