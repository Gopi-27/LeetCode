int sumIndicesWithKSetBits(int* nums, int numsSize, int k) {
    int Ans = 0;
    for(int i = 0; i < numsSize; i++){
        int cnt = 0;
        for(int j = 0; j < 30; j++){
            cnt += (i >> j) & 1;
        }
        if(cnt == k)Ans += nums[i];
    }
    return Ans;


}