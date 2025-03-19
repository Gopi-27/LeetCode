int minOperations(int* nums, int n) {
    int optr = -1;
    int cnt = 0;
    for(int i = 0; i < n; i++ ){
        if(nums[i] == 0){
            if(i + 2 >= n)return -1;
            optr = i;
            cnt++;
            if(nums[i + 1] == 0)nums[i + 1] = 1;
            else nums[i + 1] = 0;
            if(nums[i + 2] == 0)nums[i + 2] = 1;
            else nums[i + 2] = 0;
            
        }else optr = i;
    }
    return cnt;
    

}