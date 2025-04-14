bool isPrefixString(char* s, char** words, int wordsSize) {
    int flag = 0;
    int  idx = 0;
    int row = 0;
    int col = 0;
    while(s[idx] != '\0'){
        if(words[row][col] == '\0'){
            if(row == wordsSize - 1){
                flag = 1;
                break;
            }
            row++;
            col = 0;
        }
        if(s[idx] != words[row][col]){
            flag = 1;
            break;
        }
        idx++;
        col++;
    }
    if(words[row][col] != '\0')return false;
    if(flag == 0)return true;
    return false;
}