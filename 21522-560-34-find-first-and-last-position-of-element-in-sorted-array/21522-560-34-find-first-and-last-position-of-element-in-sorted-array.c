/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    *returnSize = 2;
    int* ans = (int*)calloc(2,sizeof(int));
    ans[0] = -1;
    ans[1] = -1;
    int low = 0;
    int high = numsSize - 1;
    while(low <= high){
        int mid = (low + high) >> 1;
        if(nums[mid] >= target)high = mid - 1;
        else low = mid + 1;
    }
    high = low;
    if( high < numsSize && nums[high] == target){
        ans[0] = high;
         while(high < numsSize && nums[high] == target ){
            ans[1] = high++;
         }
         return ans;
    }
    else return ans;
   
    

}