bool isHappy(int n) {
    	int sum=0;
	while(1){
		int r=n%10;
		sum+=r*r;
		n=n/10;
		if(n==0 && sum<=9){
			break;
		}else if(n==0){
			n=sum;
			sum=0;
		}
	}
	if(sum==1 || sum==7){
        return true;
	}else{
		return false;
	}
}