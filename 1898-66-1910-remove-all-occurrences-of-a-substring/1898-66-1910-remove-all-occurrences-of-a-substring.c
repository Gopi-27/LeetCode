


char* removeOccurrences(char* str, char* part) {
    char *res;
    res=NULL;
	res=strstr(str,part);
	if(res==NULL){
		return str;
	}
	char * i;
	int len=strlen(part);
	while(len--){
	for( i=res; (*i)!='\0'; i++){
		(*i)=(*(i+1));
	}	
    }
    return removeOccurrences(str,part);


}