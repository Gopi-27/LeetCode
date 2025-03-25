bool canConstruct(char* ransomNote, char* magazine) {
    int ranfrr[26] = {0};
    int magfrr[26] = {0};
    int i = 0;
    while(ransomNote[i] != '\0'){
        ranfrr[ransomNote[i] - 'a']++;
        i++;
    }
    i = 0;
    while(magazine[i] != '\0'){
        magfrr[magazine[i] - 'a']++;
        i++;
    }
    for(int i = 0; i < 26; i++){
        if(ranfrr[i] > magfrr[i])return false;
    }
    return true;

}