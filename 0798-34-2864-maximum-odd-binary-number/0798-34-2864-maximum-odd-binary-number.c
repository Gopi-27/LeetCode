char* maximumOddBinaryNumber(char* s) {
    int ocnt = 0;
    for(int i = 0; s[i] != '\0'; i++)if(s[i] == '1')ocnt++;
    int i = 0;
    while(ocnt > 1){
        s[i++] = '1';
        ocnt--;
    }
    while(s[i] != '\0'){
        s[i++] = '0';
    }
    s[i - 1] = '1';
    return s;


}