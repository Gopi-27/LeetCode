int countPrefixes(char** words, int wordsSize, char* s) {
    int cnt = 0;
    for(int i = 0; i < wordsSize; i++){
        int flag = 0;
        for(int j = 0; words[i][j] != '\0';  j++){
            if(words[i][j] != s[j]){
                flag = 1;
                break;
            }
        }
        if(flag == 0)cnt++;
    }
    return cnt;
}