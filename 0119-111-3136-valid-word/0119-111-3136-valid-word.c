int IsVowel(char ch){
    if(ch <= 'Z')ch = (ch - 'A') + 'a';
    if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')return 1;
    return 0;
}
bool isValid(char* word) {
    int len = strlen(word);
    int dcnt = 0;
    int vcnt = 0;
    int ccnt = 0;
    for(int i = 0; word[i] != '\0'; i++){
        if(word[i] >= '0' && word[i] <= '9'){
            dcnt++;
        }else if((word[i] >= 'a' && word[i] <= 'z') || (word[i] >= 'A' && word[i] <= 'Z')){
            if(IsVowel(word[i]))vcnt++;
            else ccnt++;
        }else return false;
    }
    if(len >= 3 && vcnt >= 1 && ccnt >= 1)return true;
    return false;
}