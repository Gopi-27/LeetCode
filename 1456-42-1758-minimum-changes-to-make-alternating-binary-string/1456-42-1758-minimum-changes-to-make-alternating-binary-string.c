int Min(int a,int b){
    if(a > b)return b;
    else return a;
}
int minOperations(char* s) {
    int cnt1 = 0;
    // 010101010 case
    int cnt2 = 0;
    // 101010101010 case
    for(int i = 0; s[i] != '\0'; i++){
        if(i % 2 == 0){
            if(s[i] == '1')cnt1++;
            else cnt2++;
        }else{
            if(s[i] == '0')cnt1++;
            else cnt2++;
        }
    }
    return Min(cnt1,cnt2);
}