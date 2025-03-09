int countGoodSubstrings(char* s) {
    int cnt = 0;
    int len = strlen(s);
    if(len < 3)return cnt;
    char ch1 = s[0];
    char ch2 = s[1];
    char ch3 = s[2];
    if(ch1 != ch2 && ch2 != ch3 && ch1 != ch3)cnt++;
    for(int i = 3; i < len; i++){
        ch1 = ch2;
        ch2 = ch3;
        ch3 = s[i];
        if(ch1 != ch2 && ch2 != ch3 && ch1 != ch3)cnt++;
    }
    return cnt;

    
}