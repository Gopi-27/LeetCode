int Symmetry(int n,int dig){
    int sum1 = 0;
    int sum2 = 0;
    for(int i = 0; i < dig/2; i++){
        sum1 += n % 10;
        n /= 10;
    }
    for(int i = 0; i < dig/2; i++){
        sum2 += n % 10;
        n /= 10;
    }
    if(sum1 == sum2)return 1;
    return 0;
}

int countSymmetricIntegers(int low, int high) {
   int cnt = 0;
   for(int i = low; i <= high; i++){
        int dig = log10(i) + 1;
        if(dig % 2 == 0)cnt += Symmetry(i,dig);
   }
    return cnt;
}