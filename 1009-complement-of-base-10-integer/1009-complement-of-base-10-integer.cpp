class Solution {
public:
    int bitwiseComplement(int n) {
        if(n == 0)return 1;
        int mask = 0;
        int cnt = 0;
        //  101
        while(n > 0){
            // 101
            int bit = !(n & 1);
            
            cout << bit << " ";
            mask |= (bit << cnt);    
            cnt++;
            n >>= 1;
        }
        return mask;
    }
};