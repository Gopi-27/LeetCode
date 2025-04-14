

char * sortSentence(char * s){
    char Buc[10][222];
    int left = 0;
    int right = 1;
    while(1){
        if(s[right] >= '1' && s[right] <= '9')break;
        right++;
    }
    int num = s[right] - '0';
    s[right] = '\0';
    strcpy(Buc[num],s + left);
    left = right + 2;
    right++;
    while(s[right] != '\0'){
        while(1){
            if(s[right] >= '1' && s[right] <= '9')break;
            right++;
        }
        num = s[right] - '0';
        s[right] = '\0';
        strcpy(Buc[num],s + left);
        right++;
        left = right + 1;
    }
    s[0] = '\0';
    for(int i = 1; i < 10; i++){
        if(Buc[i][0] != '\0'){
            strcat(s,Buc[i]);
            strcat(s," ");
        }
    }
    int len = strlen(s);
    s[len - 1] = '\0';
    return s;
}