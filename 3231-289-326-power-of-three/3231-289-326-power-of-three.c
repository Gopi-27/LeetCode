bool isPowerOfThree(int n) {
    double dval=(double)(log10(n)/(log10(3)));
    int ival = (int )(log10(n)/(log10(3)));
    if(ival == dval){
        return true;
    }else{
        return false;
    }
}