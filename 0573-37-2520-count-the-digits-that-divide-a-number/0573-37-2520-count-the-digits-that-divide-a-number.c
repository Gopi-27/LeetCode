int countDigits(int num) {
    int dup = num;
    int cnt = 0;
    while(dup > 0){
        if((num % (dup % 10)) == 0)cnt++;
        dup /= 10;
    }
    return cnt;
}