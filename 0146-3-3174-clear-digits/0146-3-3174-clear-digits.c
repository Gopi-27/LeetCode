void Arrange(char *str,int start){
	for(int i=start; str[i]!='\0'; i++){
		str[i]=str[i+1];
	}
}

char* clearDigits(char* str) {
    	int cnt=0;
	for(int i=0; str[i]!='\0'; i++){
		if(str[i]>='0' && str[i]<='9'){
			cnt++;
		}
	}
	while(cnt--){
	
	for(int i=0; str[i]!='\0'; i++){
		if(str[i]>='0' && str[i]<='9'){
			Arrange(str,i);
			for(int j=i-1; j>=0; j--){	
				if(str[j]>'9'){
			     	Arrange(str,j);
					break;	
				}
			}
			break;
		}
	}
}

  return str;
}