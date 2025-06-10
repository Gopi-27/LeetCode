
int maxDifference(char* s) {
    int frr[26] = {0};
    for(int i = 0; s[i] != '\0'; i++)frr[s[i] - 'a']++;
    int max_odd = - 1;
    int min_even = 100;
    for(int i = 0; i < 26; i++){
        if(frr[i] % 2 == 1 && max_odd < frr[i]){
            max_odd = frr[i];
        }else if(frr[i] % 2 == 0 && frr[i] != 0 && min_even > frr[i]){
            min_even = frr[i];
        }
    }
    return max_odd - min_even;
}