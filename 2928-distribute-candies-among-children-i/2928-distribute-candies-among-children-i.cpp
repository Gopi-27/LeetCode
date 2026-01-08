class Solution {
public:
    int distributeCandies(int n, int l) {
        if(n > l * 3)return 0;

        int r = n;
        int ans = ((r + 2) * (r + 1))/2;// tot

        if(r <= l)return ans;// one large
        r -= l + 1; // (l,s,s),(l,s,l),(l,l,s),(l,l,l);
        ans -= ((r + 2) * (r + 1))/2;
        l = min(l,r);
        int val = ((l + 1) * (r + 1)) - ((l * (l + 1))/2);
        ans -= val;
        if(r <= l)return ans - val;
        r -= l + 1;
        ans -= val - ((r + 2) * (r + 1))/2;
        return ans;       
    }
};