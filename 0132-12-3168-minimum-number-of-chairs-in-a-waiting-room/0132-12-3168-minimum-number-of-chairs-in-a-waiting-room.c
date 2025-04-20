int minimumChairs(char* s) {
    int maxpep = 0;
    int cnt = 0;
    for(int i = 0; s[i] != '\0'; i++){
        if(s[i] == 'E'){
            cnt++;
            if(maxpep < cnt)maxpep = cnt;
        }else{
            cnt--;
        }
    }
    return maxpep;
}