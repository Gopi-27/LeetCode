int balancedStringSplit(char* s) {
    int lcnt = 0;
    int rcnt = 0;
    int Ans = 0;
    for(int i = 0; s[i] != '\0'; i++){
        if(s[i] == 'R')rcnt++;
        else lcnt++;
        if(rcnt == lcnt)Ans++;
    }
    return Ans;
}