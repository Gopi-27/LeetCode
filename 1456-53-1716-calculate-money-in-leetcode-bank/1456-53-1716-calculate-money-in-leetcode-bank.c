int totalMoney(int n) {
   	int nw=n/7;
	int nd=(n%7);
	int sum=0;
	for(int i=0; i<nw; i++){
		for(int j=1+i; j<=7+i; j++){
			sum+=j;
		}
	}
	int i=nw+1;
	while(nd--){
		sum+=i;
		i++;
	}
	return sum;

}