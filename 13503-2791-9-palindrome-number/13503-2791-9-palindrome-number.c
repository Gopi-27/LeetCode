bool isPalindrome(int x) {
    int org=x; 
   long long int rn=0;
    while (x>0){
        rn = (rn*10) + (x%10);
         x=x/10;
    }
    if(org==rn){
        return true;
    }else{
        return false;
    }

}