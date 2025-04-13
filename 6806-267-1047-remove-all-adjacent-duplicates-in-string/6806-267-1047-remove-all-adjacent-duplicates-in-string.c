char* removeDuplicates(char* s) {
   char stack[strlen(s) + 1];
   int top = 0;
   stack[top] = s[0];
   for(int i = 1; s[i] != '\0'; i++){
        if( top != -1 && stack[top] == s[i]){
            top--;
        }else{
            top++;
            stack[top] = s[i];
        }
   } 
   top++;
   for(int i = 0; i < top; i++){
        s[i] = stack[i];
   }
   s[top] = '\0';
   return s;

}