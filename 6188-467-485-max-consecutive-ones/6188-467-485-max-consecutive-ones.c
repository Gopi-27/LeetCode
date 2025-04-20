int findMaxConsecutiveOnes(int* nums, int numsSize) {
   int max = 0;
   int cnt = 0;
   for(int i = 0; i < numsSize; i++){
        if(nums[i] == 1){
            cnt++;
            if(cnt > max)max = cnt;
        }
        else {
            if(cnt > max)max = cnt;
            cnt = 0;
        }
   } 
   return max;
}