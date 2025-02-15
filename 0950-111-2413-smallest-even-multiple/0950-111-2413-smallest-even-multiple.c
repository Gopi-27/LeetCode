int smallestEvenMultiple(int n) {
    int i=1;
    while(1){
        if((n*i)%2==0){
            return n*i;
        }
        i++;
    }
}