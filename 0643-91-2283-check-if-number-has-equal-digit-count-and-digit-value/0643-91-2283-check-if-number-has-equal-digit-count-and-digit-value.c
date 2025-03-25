bool digitCount(char* num) {
    int frr[10] = {0};
    for(int i = 0; num[i] != '\0'; i++){
        frr[num[i] - '0']++;
    }
    for(int i = 0; num[i] != '\0'; i++){
       if ( frr[i] != (num[i] - '0'))return false;
    }
    return true;
}