class Solution {
public:
    int partitionString(string s) {
        int grps = 1;
        int mask = 0;
        int n = s.size();
        for(int i = 0; i < n; i++){
            int k = s[i] - 'a';
            if(mask & (1 << k)){
                grps++;
                mask = (1 << k);
            }else mask |= (1 << k);
        }
        return grps;
    }
};