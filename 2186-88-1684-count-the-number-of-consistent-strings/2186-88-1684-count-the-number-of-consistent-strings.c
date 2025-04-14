

int countConsistentStrings(char * allowed, char ** words, int wordsSize){
    int frr[26] = {0};
    for(int i = 0; allowed[i] != '\0'; i++)frr[allowed[i] - 'a']++;
    int Ans = 0;
    for(int i = 0; i < wordsSize; i++){
        int flag = 0;
        for(int j = 0; words[i][j] != '\0'; j++){
            if(frr[words[i][j] - 'a'] == 0){
                flag = 1;
                break;
            }
        }
        if(flag == 0)Ans++;
    }
    return Ans;
}