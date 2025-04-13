int finalValueAfterOperations(char** operations, int operationsSize) {
    int cnt = 0;
    for(int i = 0; i < operationsSize; i++){
        if(!strcmp(operations[i],"X++") || !strcmp(operations[i],"++X")){
            cnt++;
        }else{
            cnt--;
        }
    }
    return cnt;
}