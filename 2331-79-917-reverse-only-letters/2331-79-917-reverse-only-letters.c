int IsLetter(char ch){
    if((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')){
        return 1;
    }else{
        return 0;
    }
}

char* reverseOnlyLetters(char* s) {
    int len = strlen(s);
    int i = 0;
    int j = len - 1;
    while(i < j){
        while( i < len && !IsLetter(s[i]) )i++;
        while(j >= 0 && !IsLetter(s[j]))j--;
        if(i < j){
            int temp = s[i];
            s[i] = s[j];
            s[j] = temp;
        }
        i++;
        j--;
    }
    return s;
}