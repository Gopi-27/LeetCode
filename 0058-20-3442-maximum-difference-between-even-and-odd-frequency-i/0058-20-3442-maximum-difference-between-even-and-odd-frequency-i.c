int Max(int a, int b){
    if(a > b)return a;
    else return b;
}
int maxDifference(char* s) {
    int frr[26] = {0};
    for(int i = 0; s[i] != '\0'; i++)frr[s[i] - 'a']++;
    int so = 100;
    int lo = -1;
    int se = 100;
    int le = -1;
    for(int i = 0; i < 26; i++){
        if(frr[i] % 2 == 1){
            if(so > frr[i])so = frr[i];
            if(lo < frr[i])lo = frr[i];
        }else if(frr[i] != 0){
            if(se > frr[i])se = frr[i];
            if(le < frr[i])le = frr[i];
        }
    }
    return Max(lo - se,so - le);
}