
void SubArr(int *A,int n,int start,int *frr,int k){
    if((start+k)>n){
        return ;
    }
    int Sfrr[51]={0};
    for(int i=start; i<start+k; i++){
        Sfrr[A[i]]++;
    }
    for(int i=0; i<51; i++){
        if(Sfrr[i]>0){
            frr[i]++;
        }
    }
    SubArr(A,n,start+1,frr,k);
    return ;
}

int largestInteger(int* nums, int numsSize, int k) {
    int frr[51]={0};
    int ans=-1;
    SubArr(nums,numsSize,0,frr,k);
    for(int i=0; i<51; i++){
        if(frr[i]==1){
            ans=i;
        }
    }
    return ans;
}