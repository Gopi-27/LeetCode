int titleToNumber(char* columnTitle) {
    int ans=0;
    int e=0;
    int len=strlen(columnTitle);
    for(int i=len-1; i>=0; i--){
        ans+=(columnTitle[i]-'A'+1)*(pow(26,e));
        e++;
    }
    return ans;
}