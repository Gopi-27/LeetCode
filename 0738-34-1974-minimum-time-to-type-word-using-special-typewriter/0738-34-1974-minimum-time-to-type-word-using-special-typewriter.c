int Min(int a,int b){
    if(a > b)return  b;
    return a;
}
int minTimeToType(char* word) {
    int time = 0;
    char cur = 'a';
    for(int i = 0; word[i] != '\0'; i++){
        if(word[i] > cur){
            int clc = word[i] - cur + 1;
            int anclc = (cur - 'a') + ('z' - word[i]) + 2;
            time += Min(clc,anclc);
            cur = word[i];
        }else{
            int clc = ('z' - cur) + (word[i] - 'a') + 2;
            int anclc = (cur - word[i]) + 1;
            time += Min(clc,anclc);
            cur = word[i];
        }
    }
    return time;
}