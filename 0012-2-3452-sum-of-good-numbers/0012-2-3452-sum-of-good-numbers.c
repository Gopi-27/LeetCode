int sumOfGoodNumbers(int* nums, int numsSize, int k) {
    int sum=0;
    for(int i=0; i<numsSize; i++){
    	int left;
    	int right;
    	if((i-k)<0)left=-1;
    	else left=nums[i-k];
		if((i+k)>(numsSize-1))right=-1;
		else right=nums[i+k];
    	
    	if(nums[i]>left && nums[i]>right){
    		sum+=nums[i];
		}
	}
	return sum;
    
}