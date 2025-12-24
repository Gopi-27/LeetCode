class Solution {
public:
    int GetNextPrize(vector<int>& A,int start,int k){
        int key = A[start] + k;
        int low = start + 1;
        int high = A.size() - 1;
        while(low <= high){
            int mid = (low + high) >> 1;
            if(A[mid] <= key)low = mid + 1;
            else high = mid - 1;
        }
        return low;
    }
    int rec(int level,int segments,vector<int>& prizePositions,int k,vector<vector<int>>& Dp){
        if(segments == 0)return 0;
        if(level >= prizePositions.size())return 0;
        if(Dp[level][segments] != -1)return Dp[level][segments];
        int nxt_prize = GetNextPrize(prizePositions,level,k);
        int ans = nxt_prize - level + rec(nxt_prize,segments - 1,prizePositions,k,Dp);
        ans = max(ans,rec(level + 1,segments,prizePositions,k,Dp));
        return Dp[level][segments] = ans;
    }
    int maximizeWin(vector<int>& prizePositions, int k) {
        int n = prizePositions.size();
        vector<vector<int>>Dp(n,vector<int>(3,-1));
        return rec(0,2,prizePositions,k,Dp);
    }
};