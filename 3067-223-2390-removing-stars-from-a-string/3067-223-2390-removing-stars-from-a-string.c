char* removeStars(char* s) {
    char* Ans = (char*)calloc(100001,sizeof(char));
    int top = -1;
    for(int i = 0; s[i] != '\0'; i++){
        if(s[i] == '*')top--;
        else Ans[++top] = s[i];
    }
    Ans[++top] = '\0';
    return Ans;
}