int minimumRecolors(char* blocks, int k) {
    int ans = k;
    int cnt = 0;
    int idx = 0;
    for(int i = 0; i < k; i++){
        if(blocks[i] == 'W') cnt++;
    }
    if(cnt < ans)ans = cnt;
    for (int i = k; blocks[i] != '\0'; i++){
         if(blocks[idx] == 'W') cnt--;
         if(blocks[i] == 'W') cnt++;
         if(cnt < ans) ans = cnt;
         idx++;
    }
    return ans;
}