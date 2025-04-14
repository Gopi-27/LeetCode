int findPermutationDifference(char* s, char* t) {
    int idxArr[26] = {0};
    for(int i = 0;  s[i] != '\0'; i++){
        idxArr[s[i] - 'a'] = i;
    }
    int sum = 0;
    for(int i = 0; t[i] != '\0'; i++){
        sum += abs(i - idxArr[t[i] - 'a']);
    }
    return sum;
}