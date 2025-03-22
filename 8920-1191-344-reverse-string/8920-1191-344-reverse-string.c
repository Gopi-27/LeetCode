void reverseString(char* str, int sSize) {
    for(int i = 0; i < sSize/2; i++){
        char temp = str[i];
        str[i] = str[sSize - i - 1];
        str[sSize - i - 1] = temp;
    }
    return ;
}