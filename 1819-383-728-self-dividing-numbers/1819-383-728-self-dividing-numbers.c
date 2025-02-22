/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* selfDividingNumbers(int left, int right, int* returnSize) {
    int n=1;
	int* arr=(int *)calloc(n,sizeof(int));
	for(int i=left; i<=right; i++){
		int temp=i;
		int dig=log10(i)+1;
		int cnt=0;
		while(temp>0){
			int rem=temp%10;
			if(rem!=0){
				if(i%rem==0){
					cnt++;
				}
			}
			temp/=10;
		}
		if(dig==cnt){
			arr[n-1]=i;
			n++;
		arr=(int*)realloc(arr,n*sizeof(int));
		}
	}
    *returnSize=n-1;
	return arr;
}
