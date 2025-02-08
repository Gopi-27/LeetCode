bool squareIsWhite(char* coordinates) {
    char c1=coordinates[0];
    char c2=coordinates[1];
    if(c1=='a' || c1=='c' || c1=='e'|| c1=='g'){
        if((c2-'0')%2==0){
            return true;
        }else{
            return false;
        }
    }else{
        if((c2-'0')%2==0){
            return false;
        }else{
            return true;
        }
    }
}