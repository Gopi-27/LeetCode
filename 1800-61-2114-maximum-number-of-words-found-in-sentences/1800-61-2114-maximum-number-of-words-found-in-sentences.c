int mostWordsFound(char** sentences, int sentencesSize) {
    int maxcnt = 0;
    for(int i = 0; i < sentencesSize; i++){
        int cnt = 1;
        for(int j = 0; sentences[i][j] != '\0'; j++){
            if(sentences[i][j] == ' ')cnt++;
        }
        if(maxcnt < cnt)maxcnt = cnt;
    }
    return maxcnt;
}