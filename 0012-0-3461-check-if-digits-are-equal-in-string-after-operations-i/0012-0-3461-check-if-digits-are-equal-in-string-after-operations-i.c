bool hasSameDigits(char* s) {
    while(1){
        int len=strlen(s);
        if(len==2){
            break;
        }
        for(int i=0; i<len-1; i++){
            int val=((s[i]-'0')+(s[i+1]-'0'))%10;
            s[i]=val+'0';
        }
        s[len-1]='\0';
    }
    if(s[0]==s[1]){
        return true;
    }else{
        return false;
    }
    
}