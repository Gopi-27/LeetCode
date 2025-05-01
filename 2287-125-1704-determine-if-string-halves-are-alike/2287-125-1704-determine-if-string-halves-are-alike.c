int IsVowel(char ch){
    if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'I' || ch == 'O' || ch == 'U' || ch == 'E' )return 1;
    return 0;
}
bool halvesAreAlike(char* s) {
    int len = strlen(s);
    int cnt1 = 0;
    int cnt2 = 0;
    for(int i = 0; i < len / 2; i++)cnt1 += IsVowel(s[i]);
    for(int i = len / 2; i < len; i++)cnt2 += IsVowel(s[i]);
    printf("%d %d",cnt1,cnt2);
    if(cnt1 == cnt2)return true;
    return false;
}