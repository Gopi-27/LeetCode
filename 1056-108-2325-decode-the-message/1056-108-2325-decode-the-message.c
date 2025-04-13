char* decodeMessage(char* key, char* message) {
    int frr[26] = {0};
    int idx = 0;
    for(int i = 0; key[i] != '\0'; i++){
        if(key[i] != ' ' && frr[key[i] - 'a'] == 0){
            key[idx++] = key[i];
            frr[key[i] - 'a'] = -1;
        }
    }
    int Decode[26] = {0};
    for(int i = 0; i < idx; i++){
        Decode[key[i] - 'a'] = i ;
    }
    for(int i = 0; message[i] != '\0'; i++){
        if(message[i] != ' '){
            message[i] = Decode[message[i] - 'a'] + 'a';
        }
    }
    return message;

}