int sumOfSquares(int* nums, int n) {
    int ans = 0;
    for(int i = 0; i < n; i++){
        if((n % (i + 1) ) == 0)ans += nums[i] * nums[i];
    }
    return ans;
}