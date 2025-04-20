int maxPower(char* s) {
    int max = 0;
    int i = 0;
    while(s[i] != '\0'){
        char ch = s[i];
        int cnt = 0;
        while(s[i] != '\0' && s[i] == ch){
            cnt++;
            i++;
        }
        if(cnt > max)max = cnt;
    }
    return max;
}