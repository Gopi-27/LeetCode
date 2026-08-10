int minBitFlips(int start, int goal) {
    int res = start ^ goal;
    int cnt = 0;
    for(int i = 0; i < 32; i++){
       if((res >> i) & 1)cnt++;
    }
    return cnt;
}