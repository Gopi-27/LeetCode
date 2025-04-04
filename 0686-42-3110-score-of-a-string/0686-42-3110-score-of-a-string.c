int scoreOfString(char* s) {
    int scr = 0;
    for(int i = 1; s[i] != '\0'; i++){
        scr += abs((s[i] - s[i -1]));
    }
    return scr;
}