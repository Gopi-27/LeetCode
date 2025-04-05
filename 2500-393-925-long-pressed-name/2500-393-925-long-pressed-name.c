bool isLongPressedName(char* name, char* typed) {
    int i = 0; int j = 0;
    if(name[0] != typed[0])return false;
    while(name[i] != '\0' && typed[j] != '\0'){
        if(name[i] == typed[j]){
            i++;
            j++;
        }else if(typed[j - 1] == typed[j]){
            j++;
        }else {
            return false;
        }
    }
    while(typed[j] != '\0'){
        if(typed[j - 1] != typed[j])return false;
        j++;
    }
    if(name[i] != '\0')return false;
    return true;
}