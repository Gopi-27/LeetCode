int DigSum(int n){
    int sum=0;
    while(n>0){
        sum+=n%10;
        n=n/10;
    }
    return sum;
}
int countLargestGroup(int n) {
    int frr[10001]={0};
    int max=0;
    for(int i=1; i<=n; i++){
        int dig=DigSum(i);
        frr[dig]++;
        if(max<frr[dig]){
            max=frr[dig];
        }
    }

    int cnt=0;
    for(int i=0; i<10001; i++){
        if(max==frr[i]){
            cnt++;
        }
    }
    return cnt;

}