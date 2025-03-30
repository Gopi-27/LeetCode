int countKDifference(int* nums, int n, int k) {
    int cnt = 0;
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(abs(nums[i] - nums[j]) == k)cnt++;
        }
    }
    return cnt;
}