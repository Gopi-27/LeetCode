long long calculateScore(char** instructions, int instructionsSize, int* values, int valuesSize) {
    long long int  cnt = 0;
    int n = instructionsSize;
    int i = 0;
    int* Vis = (int*)calloc(n,sizeof(int));
    while(i >= 0 && i < n){
        if(Vis[i] == 1)return cnt;
        Vis[i] = 1;
        if(strcmp(instructions[i],"jump") == 0){
            i = i + values[i];
        }else{
            cnt += values[i];
            i++;
        }
        
    }
    return cnt;
}