int hammingWeight(int n) {
      int len=log2(n)+1;
    int arr[len];
    int i=0;
    while(n>0){
    	int rem=n%2;
    	arr[i]=rem;
    	n=n/2;
    	i++;
	}
	int cnt=0;
	for(int i=0; i<len; i++){
		if(arr[i]==1){
			cnt++;
		}
	}
	return cnt;
}