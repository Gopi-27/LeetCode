bool checkPerfectNumber(int num) {
    int sum=0;
    for(int i=1; (i*i)<=num ; i++){
        if(num%i==0){
            sum+=i+(num/i);
        }
    }
    if(num==1){
        sum=sum-2;
    }else{
    sum=sum-num;
    }
    if(sum==num){
        return true;
    }else{
        return false;
    }

}