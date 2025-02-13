

char * mergeAlternately(char * word1, char * word2){
    // Getting the length of string word1
    int len1=strlen(word1);
    // Getting the length of string word2
	int len2=strlen(word2);
    // Allocating the memory for destination string of length len1+len2+1
	char * des=(char *)calloc(len1+len2+1,sizeof(char));
	int i=0;
	int j=0;
	int k=0;
    // Alternately arrange the character into the destination string
	while(i<len1 && j<len2){
		des[k++]=word1[i++];
		des[k++]=word2[j++];
	}
    // if the characters in the word1 is left arranging them into destination string
	while(i<len1)des[k++]=word1[i++];
    // if the characters in the word2 is left arranging them into destination string
	while(j<len2)des[k++]=word2[j++];
	return des;


}