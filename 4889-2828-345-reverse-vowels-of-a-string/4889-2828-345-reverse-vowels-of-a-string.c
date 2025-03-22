int IsVowel(char ch){
    if(ch == 'A' || ch == 'a' || ch == 'E'|| ch == 'e' || ch == 'i' || ch == 'I' || ch == 'O' || ch == 'o' || ch == 'U' || ch == 'u' ){
        return 1;
    }else{
        return 0;
    }
}
char* reverseVowels(char* str) {
    int len = strlen(str);
    int i = 0;
    int j = len - 1;

    while(i < j){
        while( i < len && !IsVowel(str[i]))i++;
        while(j >= 0 && !IsVowel(str[j]))j--;
        if(i < j){
            char temp = str[i];
            str[i] = str[j];
            str[j] = temp;
        }
        i++;
        j--;

    }
    return str;
}