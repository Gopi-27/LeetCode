int alternateDigitSum(int n) {
    int sum=0;
    int dig=log10(n)+1;
    if((dig%2)!=0){
        int sign=1;
        while(n>0){
            sum+=(sign)*(n%10);
            n=n/10;
            if(sign==(-1)){
                sign=1;
            }else{
                sign=-1;
            }
        }

    }else{
        int sign=-1;
        while(n>0){
            sum+=(sign)*(n%10);
            n=n/10;
            if(sign==(-1)){
                sign=1;
            }else{
                sign=-1;
            }
        }
    }
    return sum;
}