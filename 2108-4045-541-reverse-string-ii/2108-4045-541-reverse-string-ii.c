void Reverse(int i ,int n,char *s){
    for(int j = i; j < (i + n)/ 2; j ++){
        int temp = s[j];
        s[j] = s[i + n - j - 1];
        s[i + n - j - 1] = temp;
    }
    return ;
}

char* reverseStr(char* s, int k) {
    int len = strlen(s);
    int i = 0;
    while((i + k) <= len){
        Reverse(i,i + k,s);
        i += 2 * k;
    }
    Reverse(i,len,s);
    return s;
}