bool hasSpecialSubstring(char* s, int k) {
        int f[26]={0};
    int cnt=1;
    char var=s[0];
    if(f[var-'a']<cnt){
    	f[var-'a']=cnt;
	}
    for(int i=1; s[i]!='\0'; i++){
    	if(f[var-'a']<cnt){
    		f[var-'a']=cnt;
		}
		if(s[i]==var){
			cnt++;
		}else{
            if(f[var-'a']!=k){
				f[var-'a']=0;
			}
			var=s[i];
			cnt=1;
		}
	}
    if(f[var-'a']<cnt){
    	f[var-'a']=cnt;
	}
	for(int i=0; i<26; i++){
		if(f[i]==k){
			return true;
		}
	}
	return false;
    
   
}