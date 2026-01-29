class Solution {
public:
    bool isThree(int n) {
       if(n <= 3)return false;
       int cnt = 0;
       for(int i = 2; i * i <= n; i++){
            if(n % i == 0){
                cnt++;
                if(n/i != i)cnt++;
            }
       }
       return cnt == 1;
    }
};