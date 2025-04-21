int countAsterisks(char* s) {
    int starcnt = 0;
    int barcnt = 0;
    for(int i = 0; s[i] != '\0'; i++){
        if(s[i] == '|')barcnt++;
        if(barcnt % 2 == 0 && s[i] == '*')starcnt++;
    }
    return starcnt;
}