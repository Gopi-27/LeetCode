int passThePillow(int n, int k) {
       n--;
    int quo = k / n;
    if(quo % 2 == 0){
        return (k % n) + 1;
    }else{
        return n - (k % n) + 1;
    }
}