bool checkPowersOfThree(int n) {
    while(1){
        if(n==1){
            return true;
        }
        int rem=n%3;
        int quo=n/3;
        if(rem>=2){
        return false;
        }
        n=quo;
    }
}