char* capitalizeTitle(char* title) {
    int len = strlen(title);
    int left  = 0;
    int right = -1;
    while(right < len){
        left = right + 1;
        right++;
        while(right < len && title[right] != ' ' && title[right] != '\0')right++;

        int dif = right - left;
        if(dif <= 2){
            for(int i = left; i < right; i++){
                if(title[i] >= 'A' && title[i] <= 'Z'){
                    title[i] = title[i] - 'A' + 'a';
                }
            }
        }else{
            if(title[left] >= 'a' && title[left] <= 'z'){
                title[left] = title[left] - 'a' + 'A';
            }
            for(int i = left + 1; i < right; i++){
                if(title[i] >= 'A' && title[i] <= 'Z'){
                    title[i] = title[i] - 'A' + 'a';
                }
            }
        }
    }
    return title;
}