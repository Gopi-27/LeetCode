char* GetRLE(char* str){
    char* RLE = (char*)calloc(10000,sizeof(char));
    int rlidx = 0;
    int idx = 0;
    while(str[idx] != '\0'){
        int i = idx;
        int cnt = 0;
        while(str[i] != '\0' && str[i] == str[idx]){
            cnt++;
            i++;
        }
        char chcnt = cnt + '0';
        RLE[rlidx++] = chcnt;
        RLE[rlidx++] = str[idx];
        idx = i;
    }
    return RLE;
}


char* countAndSay(int n) {
    if(n <= 1)return "1";
    char* Ans = (char*)calloc(10000,sizeof(char));
    Ans = "1";
    for(int i = 0; i < n - 1; i++){
        Ans = GetRLE(Ans);
    }
    return Ans;
}