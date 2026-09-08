class Solution {
public:
    int Count(int n){
        int cnt = 0;
        while(n > 0){
            cnt++;
            n /= 10;
        }
        if(cnt % 3 == 0)return (cnt/3) - 1;
        return cnt/3;
    }
    int countCommas(int n) {
        int cnt = 0;
        for(int i = 1; i <= n; i++){
            cnt += Count(i);
        }
        return cnt;
    }
};