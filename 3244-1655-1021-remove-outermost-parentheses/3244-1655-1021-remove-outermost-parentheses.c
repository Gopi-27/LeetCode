char* removeOuterParentheses(char* s) {
    int len = strlen(s);
    char *Ans =(char *)calloc(len , sizeof(char));
    int idx = 0;
    int Top = 0;
    for(int i = 0; s[i] != '\0'; i++){
       if(s[i] == '('){
            if(Top == 0)Top++;
            else{
                Top++;
                Ans[idx++] = '(';
            }
       }else{
            if(Top == 1)Top--;
            else{
                Top--;
                Ans[idx++] = ')' ;
                
            }

       }
    }
    return Ans;
}