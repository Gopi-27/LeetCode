class Solution {
public:
    int rec(int level,int start,int n){
        // pruning
        
        // base case
        if(level > n)return 1;
        // cache

        // compute
        int ans = 0;
        for(int i = start; i <= 5; i++){
            ans += rec(level + 1,i,n);
        }
        // save and return
        return ans;     
    }
    int countVowelStrings(int n) {
        return rec(1,1,n);
    }
};