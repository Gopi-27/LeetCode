bool isPalindrome(char* s) {
    char str[200001];
    int idx = 0;
    for(int i = 0;  s[i] != '\0'; i++){
        if(s[i] >= 'A' && s[i] <= 'Z'){
            str[idx++] = s[i] - 'A' + 'a';
        }else if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9')){
            str[idx++] = s[i];
        }
    }
    for(int i = 0; i < idx / 2; i++){
        if(str[i] != str[idx - i - 1])return false;
    }
    return true;
}