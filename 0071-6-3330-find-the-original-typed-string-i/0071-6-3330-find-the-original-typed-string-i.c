int possibleStringCount(char* word) {
    int ans = 0;
    for(int i = 1; word[i] != '\0'; i++){
        if(word[i] == word[i - 1]){
            ans++;
        }
    }
    return ans + 1;



}