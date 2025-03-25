char* greatestLetter(char* s) {
    int afrr[26] = {0};
    int Afrr[26] = {0};
    for(int i = 0; s[i] != '\0'; i++){
        if(s[i] >= 'A' && s[i] <= 'Z')Afrr[s[i] - 'A']++;
        else afrr[s[i] - 'a']++;
    }
    char * ans = (char *)calloc(2,sizeof(char));
    ans[0] = '\0';
    for(int i = 0; i < 26; i++){
        if(afrr[i] > 0 && Afrr[i] > 0)ans[0] = i + 'A';
    }
    return ans;
}