bool isCircularSentence(char* sent) {
    char first = sent[0];
    int i = 0;
    char prev = first;
    while(sent[i + 1] != '\0'){
        while(sent[i + 1] != '\0' && sent[i + 1] != ' ')i++;
        if(sent[i + 1] == '\0'){
            if(sent[i] == first)return true;
            return false;
        }
        prev = sent[i];
        i += 2;
        if(sent[i] != prev)return false;
    }
    return true;

}