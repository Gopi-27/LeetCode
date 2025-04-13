int getLucky(char* s, int k) {
    int sum = 0;
    for(int i = 0; s[i] != '\0'; i++){
       int pla = (s[i] - 'a') + 1;
        while(pla > 0){
            sum += pla % 10;
            pla /= 10;
        }

    }
    int nsum = sum;
    k--;
    while(k--){
        sum = nsum;
        nsum = 0;
            while(sum > 0){
                nsum += sum % 10;
                sum /= 10;
            }
    }
    return nsum;


}