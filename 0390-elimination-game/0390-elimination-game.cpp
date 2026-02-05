class Solution {
public:
    int lastRemaining(int n) {
        int d = 1;
        int start = 1;
        int end = n;
        int tot = n;
        while(tot > 1){
            int nStart;
            if(tot % 2 == 0){
                nStart = start + (tot - 1) * d;
            }else{
                nStart = start + (tot - 2) * d;
            }
            cout << nStart << endl;
            d *= -2;
            start = nStart;
            tot /= 2;
        }
        return start;         
    }
};