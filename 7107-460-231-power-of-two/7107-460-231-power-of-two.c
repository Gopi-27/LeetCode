bool isPowerOfTwo(int n) {
    double dval=(double)log2(n);
    int ival=(int )log2(n);
    if(ival==dval){
        return true;
    }else{
        return false;
    }
}