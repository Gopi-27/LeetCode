int findKOr(int* nums, int numsSize, int k) {
    int frr[31] = {0};
    for(int i = 0; i < numsSize; i++){
        for(int j = 0; j < 31; j++){
             frr[j] += (nums[i] >> j ) & 1;
        }
    }
    for(int i = 0; i < 31; i++){
        if(frr[i] >= k)frr[i] = 1;
        else frr[i] = 0;
    }
    int Ans  = 0;
    for(int i = 0; i < 31; i++){
        Ans += pow(2,i) * frr[i];
    }
    return Ans;
}