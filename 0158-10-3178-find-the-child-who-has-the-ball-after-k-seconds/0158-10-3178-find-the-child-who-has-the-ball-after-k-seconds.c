int numberOfChild(int n, int k) {
    n--;
    int quo = k / n;
    if(quo % 2 == 0){
        return (k % n);
    }else{
        return n - (k % n);
    }
}