/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findWordsContaining(char** words, int wordsSize, char x, int* returnSize) {
    int* Ans = (int *)malloc(wordsSize * sizeof(int));
    int idx = 0;
    for(int i = 0; i < wordsSize; i++){
        for(int j = 0; words[i][j] != '\0'; j++){
            if(words[i][j] == x){
                Ans[idx++] = i;
                break;
            }
        }
    }
    *returnSize = idx;
    return Ans;
}