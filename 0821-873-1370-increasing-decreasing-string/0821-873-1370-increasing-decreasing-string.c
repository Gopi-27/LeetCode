char* sortString(char* s) {
    int frr[26] = {0};
    for(int i = 0; s[i] != '\0'; i++)frr[s[i] - 'a']++;
    int max = 0;
    for(int i = 0; i < 26; i++)if(max < frr[i])max = frr[i];
    if(max % 2 == 0){
        int idx = 0;
        while(max--){
            for(int i = 0; i < 26; i++){
                if(frr[i] > 0){
                    s[idx++] = i + 'a';
                    frr[i]--;
                }
            }
            for(int i = 25; i >= 0; i--){
                if(frr[i] > 0){
                    s[idx++] = i + 'a';
                    frr[i]--;
                }
            }
        }
        return s;
    }else{
        int idx = 0;
        max--;
        while(max--){
            for(int i = 0; i < 26; i++){
                if(frr[i] > 0){
                    s[idx++] = i + 'a';
                    frr[i]--;
                }
            }
            for(int i = 25; i >= 0; i--){
                if(frr[i] > 0){
                    s[idx++] = i + 'a';
                    frr[i]--;
                }
            }
        }
        for(int i = 0; i < 26; i++){
            if(frr[i] > 0){
                s[idx++] = i + 'a';
                frr[i]--;
            }
        }
        return s;

    }
}