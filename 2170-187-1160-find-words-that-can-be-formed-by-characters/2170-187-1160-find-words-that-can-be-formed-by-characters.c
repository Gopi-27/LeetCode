int countCharacters(char** words, int wordsSize, char* chars) {
    int sum = 0;
    int chfrr[26] = {0};
    int i = 0;
    while(chars[i] != '\0'){
        chfrr[chars[i] - 'a']++;
        i++;
    }
    for(int j = 0; j < wordsSize; j++){
        int dummyfrr[26] = {0};
        i = 0;
        while(words[j][i] != '\0'){
            dummyfrr[words[j][i] - 'a']++;
            i++;
        }
        int flag = 0;
        for(int k = 0; k < 26; k++){
            if(dummyfrr[k] > chfrr[k]){
                flag = 1;
                break;
            }
        }
        if(flag == 0)sum += i;
    }
    return sum;
}