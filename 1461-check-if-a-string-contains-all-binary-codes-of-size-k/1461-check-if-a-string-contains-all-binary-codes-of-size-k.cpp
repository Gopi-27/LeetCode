class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = s.size();
        if(n < k)return false;
        int mask = 0;
        for(int i = 0; i < k; i++){
            mask <<= 1;
            mask |= (s[i] - '0');
        }
        int tot = (1 << k);
        vector<bool>Memo(tot);
        Memo[mask] = 1;
        tot--;
        for(int i = k; i < n; i++){
            int shadow = ~(1 << (k - 1));
            mask &= shadow;
            mask <<= 1;
            mask |= (s[i] - '0');
            if(!Memo[mask]){
                Memo[mask] = 1;
                tot--;
            }
        }
        return tot == 0;
    }
};