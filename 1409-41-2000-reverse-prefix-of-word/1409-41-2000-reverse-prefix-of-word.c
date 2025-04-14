void Reverse(char* str,int right){
    int left = 0;
    while(left < right){
        char temp = str[right];
        str[right] = str[left];
        str[left] = temp;
        right--;
        left++;
    }
    return ;
}
char* reversePrefix(char* word, char ch) {
    int idx = - 1;
    for(int i = 0; word[i] != '\0'; i++){
        if(word[i] == ch){
            idx = i;
            break;
        }
    }
    Reverse(word,idx);
    return word;
}