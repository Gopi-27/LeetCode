int DigSum(int n){
    // adding the digits in the array
	int sum=0;
	while(n>0){
		sum+=n%10;
		n=n/10;
	}
	return sum;
}

int maximumSum(int* arr, int n) {
   	int ans=-1;
    // to store the maximum element of particluar DigSum based on the indices
	int frr[100]={0};
    // to check the DigSum occurences 
	int cnt[100]={0};
	
	for(int i=0; i<n; i++){
        // storing the DigSum of the ith element in the array
		int isum=DigSum(arr[i]);
        // increasing the DigSum occurence
		cnt[isum]++;
		if(cnt[isum]>=2 && ans<(arr[i]+frr[isum])){
			   	ans=arr[i]+frr[isum];
		}
        // storing the maximum element of particular DigSum based on the index
		if(frr[isum]<=arr[i]){
			frr[isum]=arr[i];
		}
				
	}
	return ans;

}