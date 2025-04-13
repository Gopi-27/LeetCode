bool makeEqual(char** words, int wordsSize) {
    int frr[26] = {0};
    for(int i = 0; i < wordsSize; i++){
        for(int j = 0; words[i][j] != '\0'; j++){
            frr[words[i][j] - 'a']++;
        }
    }
    for(int i = 0; i < 26; i++){
        if(frr[i] % wordsSize == 0){
            continue;
        }else{
            return false;
        }
    }
    return true;
}