char GetSmall(char ch){
    return ch - 'A' + 'a';
}
int countKeyChanges(char* s) {
    int cnt = 0;
    if(s[0] >= 'A' && s[0] <= 'Z')s[0] = GetSmall(s[0]);
    for(int i = 1; s[i] != '\0'; i++){
        if(s[i] >= 'A' && s[i] <= 'Z'){
            s[i] = GetSmall(s[i]);
        }
        if(s[i] != s[i - 1])cnt++;
    }
    return cnt;
}