void Reverse(char* s,int n){
    for(int i = 0; i < n/2; i++){
        int temp = s[i];
        s[i] = s[n - i - 1];
        s[n - i - 1] = temp;
    }
    return ;
}
char* finalString(char* s) {
    for(int i = 0; s[i] != '\0'; i++){
        if(s[i] == 'i'){
            Reverse(s,i);
            for(int j = i;  s[j] != '\0'; j++)s[j] = s[j + 1];
            i--;
        }
    }
    return s;
}