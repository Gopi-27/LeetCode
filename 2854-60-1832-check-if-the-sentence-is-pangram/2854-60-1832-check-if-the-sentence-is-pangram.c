bool checkIfPangram(char* sentence) {
    int frr[26] = {0};
    for(int i = 0; sentence[i] != '\0'; i++)frr[sentence[i] - 'a']++;
    for(int i = 0; i < 26; i++)if(frr[i] == 0)return false;
    return true;
}