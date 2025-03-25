char* largestGoodInteger(char* num) {
    int len = strlen(num);
    char ch = '0';
    int l = 0;
    int r = 0;
    int flag = 0;
    while( r < len){
        l = r;
        while( r < len && num[l] == num[r])r++;
        if((r - l) >= 3){
            flag = 1;
            if(ch <= num[l]){
                ch = num[l];
            }
        }
    }
    if(flag == 1){
        char* ans = (char*)calloc(4,sizeof(char));
        for(int i = 0; i < 3; i++)ans[i] = ch;
        return ans;
    }else{
        return "";
    }

}




