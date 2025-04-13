int minimizedStringLength(char* s) {
    int frr[26] = {0};
    for(int i = 0; s[i] != '\0'; i++){
        frr[s[i] - 'a']++;
    }
    int idx = 0;
    for(int i = 0; s[i] != '\0'; i++){
        if(frr[s[i] - 'a'] > 0){
            idx++;
            frr[s[i] - 'a'] = -1;
        }
    }
    
    return idx;
}