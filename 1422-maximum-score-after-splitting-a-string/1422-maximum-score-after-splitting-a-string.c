int maxScore(char* s) {
    int ans = 0;
    int cnt0 = 0;
    int cnt1 = 0;
    for(int i = 0; s[i] != '\0'; i++){
        if(s[i] == '1')cnt1++;
    }
    for(int i = 0; s[i + 1] != '\0'; i++){
        if(s[i] == '0'){
            cnt0++;
            if(ans < (cnt0 + cnt1)){
                ans = cnt0 + cnt1;
            }
        }else{
            cnt1--;
            if(ans < (cnt0 + cnt1)){
                ans = cnt0 + cnt1;
            }
        }
    }
    return ans;
}