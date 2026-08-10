/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 int IsPrime(int n){
    if(n==1)return -1;
    int fact=2;
    for(int i=2; i*i<=n; i++){
        if(n%i==0){
            fact+=2;
            break;
        }
    }
    if(fact==2)return n;
    else return -1;
 }
int* closestPrimes(int left, int right, int* returnSize) {
    *returnSize = 2 ;
    int num1 = - 1 ;
    int num2 = - 1 ;
    int prev ;
    int cnt = 0 ;
    int * Ans = (int *)malloc(2*sizeof(int));
    for(int i=left; i<=right; i++){
        if(IsPrime(i) == i){
            cnt++;

            if(cnt == 1){
                num1 = i ;
            }else if(cnt==2){
                num2 = i ;
                prev = num2 ;
            }else{
                int dif = num2 - num1 ;
                int tdif = i - prev ;
                if( dif > tdif ){
                    num1 = prev ;
                    num2 = i ;
                }
                prev = i ;
            }
        }  
    }
    
    if(cnt<2){
        Ans[0] = - 1;
        Ans[1] = - 1;
        return Ans;
    }
    Ans[0] = num1 ;
    Ans[1] = num2 ;
    return Ans;
}