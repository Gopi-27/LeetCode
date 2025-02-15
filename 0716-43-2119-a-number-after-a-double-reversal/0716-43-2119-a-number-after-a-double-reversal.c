int ReverseNum(int n){
    int rn=0;
    while(n>0){
    rn=(rn*10)+n%10;
    n/=10;
    }
    return rn;
}

bool isSameAfterReversals(int num) {
    int rev1=ReverseNum(num);
    int rev2=ReverseNum(rev1);
    if(rev2==num){
        return true;
    }else{
        return false;
    }


}