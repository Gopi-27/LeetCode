int DigSum(int n){
	int sum=0;
	while(n>0){
		sum+=n%10;
		n/=10;
	}
	return sum;
}
int differenceOfSum(int* nums, int numsSize) {
    int ele_sum=0;
    int dig_sum=0;
    for(int i=0; i<numsSize; i++){
    	ele_sum+=nums[i];
    	dig_sum+=DigSum(nums[i]);
	}
	if(ele_sum>dig_sum){
		return ele_sum-dig_sum;
	}else{
		return dig_sum-ele_sum;
	}
}