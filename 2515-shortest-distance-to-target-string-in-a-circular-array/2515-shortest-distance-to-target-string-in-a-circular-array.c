int Min(int a,int b){
    if(a > b)return b;
    return a;
}
int closestTarget(char** words, int n, char* target, int startIndex) {
    if(strcmp(words[startIndex],target) == 0)return 0;
    int fdis = 1;
    int bdis = 1;
    int i = (startIndex + 1) % n;
    while(1){
        if(strcmp(words[i],target) == 0)break;
        fdis++;
        i = (i + 1) % n;
        if(i == startIndex)return -1;
    }
    i = (startIndex - 1 + n ) % n ;
    while(1){
        if(strcmp(words[i],target) == 0)break;
        bdis++;
        i = (i - 1 + n) % n;
        if(i == startIndex)return -1;
    }
    return Min(fdis,bdis);

}