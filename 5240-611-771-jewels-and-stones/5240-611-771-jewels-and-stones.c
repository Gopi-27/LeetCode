int numJewelsInStones(char* jewels, char* stones) {
    int Sjewfrr[26] = {0};
    int Cjewfrr[26] = {0};
    for(int i = 0; jewels[i] != '\0'; i++){
        if(jewels[i] >= 'a' && jewels[i] <= 'z'){
            Sjewfrr[jewels[i] - 'a']++;
        }else{
            Cjewfrr[jewels[i] - 'A']++;
        }
    }
    int cnt = 0;
    for(int i = 0; stones[i] != '\0'; i++){
        if(stones[i] >= 'a' && stones[i] <= 'z'){
            if(Sjewfrr[stones[i] - 'a'] > 0)cnt++;
        }else{
            if(Cjewfrr[stones[i] - 'A'] > 0)cnt++;
        }
    }
    return cnt;
}