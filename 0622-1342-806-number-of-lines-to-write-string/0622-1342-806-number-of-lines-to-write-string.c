

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* numberOfLines(int* widths, int widthsSize, char * s, int* returnSize){
          int lcnt=0;
    int wcnt=100;
    for(int i=0; s[i]!='\0'; i++){
        if((wcnt+widths[s[i]-'a'])>100){
            lcnt++;
            wcnt=0;
        }
        wcnt+=widths[s[i]-'a'];

    }
    *returnSize=2;
    int *res=(int *)malloc(2*sizeof(int));
    res[0]=lcnt;
    res[1]=wcnt;
    return res;

 
}