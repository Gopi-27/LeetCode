bool areOccurrencesEqual(char* s) {
    int frr[26];
    for(int i = 0; s[i] != '\0'; i++){
        frr[s[i] - 'a']++;
    }
    int i = 0;
    while(frr[i] <= 0)i++;
    int prev = frr[i++];
    while(i < 26){
        if(frr[i] > 0 && frr[i] != prev)return false;
        i++;
    }
    return true;
}