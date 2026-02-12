bool comp(pair<int,int>& a,pair<int,int>& b){
    if(a.second < b.second)return true;
    if(a.second > b.second)return false;
    return a.first < b.first;
}
class Solution {
public:
    int rec(int i,vector<int>& Dp){
        if(i == 1)return 0;
        if(Dp[i] != -1)return Dp[i];
        if(i % 2 == 0)return 1 + rec(i/2,Dp);
        return 1 + rec(3 * i + 1,Dp);
    }
    int getKth(int lo, int hi, int k) {
        int n = hi * 1000;
        vector<int>Dp(n,-1);
        for(int i = 1; i <= hi; i++){
            if(Dp[i] == -1){
                Dp[i] = rec(i,Dp);
            }
        }

        vector<pair<int,int>>A(hi - lo + 1);
        for(int i = 0; i < hi - lo + 1; i++){
            A[i].first = lo + i;
            A[i].second = Dp[lo + i];
        }
        sort(A.begin(),A.end(),comp);
        return A[k - 1].first;
    }
};