class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(),piles.end());
        int n = piles.size();
        int ans = 0;
        int quo = n/3;
        int i = n - 2;
        while(quo--){
            ans += piles[i];
            i -= 2;
        }
        return ans;
    }
};