int Max(int a,int b){
    if(a > b)return a;
    else return b;
}
int maximumCount(int* nums, int numsSize) {
    int low = 0;
    int high = numsSize - 1;
    while(low < high ){
        int mid = (low + high) >> 1;
        if(nums[mid] > 0)high = mid - 1;
        else low = mid + 1;
    }
    int LnegIdx = - 1;
    int FposIdx = numsSize;
    if( nums[low] > 0){
        FposIdx = low;
        low--;
        while(low >= 0){
            if(nums[low] < 0)break;
            low--;
        }
        LnegIdx = low;
    }else if (nums[low] < 0){
        LnegIdx = low;
        low++;
        while(low <= numsSize - 1){
            if(nums[low] > 0)break;
            low++;
        }
        FposIdx = low;
    }else{
        low--;
        while(low >= 0){
            if(nums[low] < 0)break;
            low--;
        }
        LnegIdx = low;
        high++;
        while(high <= numsSize - 1){
            if(nums[high] > 0)break;
            high++;
        }
        FposIdx = high;
    }
    
    return Max(LnegIdx + 1,numsSize - FposIdx);

}





