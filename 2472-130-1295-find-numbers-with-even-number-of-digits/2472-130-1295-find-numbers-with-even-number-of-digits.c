int findNumbers(int* nums, int numsSize) {
    	int cnt=0;
	for(int i=0; i<numsSize; i++){
		int dig=log10(nums[i])+1;
		if(dig%2==0){
			cnt++;
		}
	}
	return cnt;
}