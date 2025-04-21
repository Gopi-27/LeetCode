int GetRow(char ch){
    // GBR
    if(ch == 'G')return 0;
    if(ch == 'B')return 1;
    return 2;
}
int countPoints(char* s) {
    int frr[3][10] = {0};
    for(int i = 0; s[i] != '\0'; i += 2){
        frr[GetRow(s[i])][s[i + 1] - '0']++;
    }
    int cnt = 0;
    for(int i = 0; i < 10; i++){
        if(frr[0][i] > 0 && frr[1][i] > 0 && frr[2][i] > 0)cnt++;
    }
    return cnt;
}