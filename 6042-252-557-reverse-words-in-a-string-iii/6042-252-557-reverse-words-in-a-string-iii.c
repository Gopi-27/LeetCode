void Reverse(char* str,int left,int right){
    while(left < right){
        char temp = str[right];
        str[right] = str[left];
        str[left] = temp;
        right--;
        left++;
    }
    return ;
}

char* reverseWords(char* s) {
    if(s[1] == '\0')return s;
    int left = 0;
    int right = 0;
    while(s[right] != ' ' && s[right] != '\0')right++;
    Reverse(s,left,right - 1);
    while(s[right] != '\0'){
        left = right;
        right++;
        while(s[right] != ' ' && s[right] != '\0')right++;
        Reverse(s,left + 1,right - 1);
    }
    return s;
}