int IsPrime(int n){
    if(n == 1)return 0;
    for(int i = 2; i * i <= n; i++){
        if(n % i == 0)return 0;
    }
    return 1;
}
int IsPalindrome(int n){
    long long int rn = 0;
    int org = n;
    while(n > 0){
        rn = (rn * 10) + (n % 10);
        n /= 10;
    }
    if(org == rn)return 1;
    else return 0;
}


int primePalindrome(int n) {
    while(1){
        if (n >= 1e3 && n < 1e4)n = 1e4;
        else if (n > 1e5 && n < 1e6)n = 1e6;
        else if (n > 1e7 && n < 1e8)n = 1e8;
        if(IsPalindrome(n)){
            if(IsPrime(n)){
                return n;
            }
        }
        n++;
    }
}