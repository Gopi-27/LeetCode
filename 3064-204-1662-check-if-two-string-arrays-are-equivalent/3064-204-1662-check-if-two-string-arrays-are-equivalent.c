bool arrayStringsAreEqual(char** word1, int word1Size, char** word2, int word2Size) {
    int row1 = 0;
    int col1 = 0;
    int row2 = 0;
    int col2 = 0;
    while(row1 < word1Size && row2 < word2Size){
        while(word1[row1][col1] != '\0' && word2[row2][col2] != '\0'){
            if(word1[row1][col1] != word2[row2][col2]){
                return false;
            }
            col1++;
            col2++;
        }
        if(word1[row1][col1] == '\0'){
            row1++;
            col1 = 0;
        }
        if(word2[row2][col2] == '\0'){
            row2++;
            col2 = 0;
        }
         
    }
    if(row1 == word1Size && row2 == word2Size)return true;
    return false;
}