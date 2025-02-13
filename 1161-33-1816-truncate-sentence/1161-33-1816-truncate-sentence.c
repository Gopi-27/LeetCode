char* truncateSentence(char* s, int k) {
    // Getting the length of the string 's'
    	int len=strlen(s);
    // Allocating the memory for des string 
    	char *des=(char *)calloc(len+1,sizeof(char));
    // Coping the string 's' to string 'des'
    	strcpy(des,s);
    	int cnt=0;
    	int i=0;
    	while(i<len){
            // counting the number of spaces
    		if(des[i]==' '){
    			cnt++;
			}
			// if count is equal to k then stop 
			if(cnt==k){
				des[i]='\0';
				break;
			}
			i++;
		}
    	
    	return des;
}