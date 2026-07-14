class Solution {
public:
    int Dp[201][201][201];
    int mod = 1e9 + 7;
    int rec(int idx,int seq1,int seq2,vector<int>& nums){
        if(idx >= nums.size())return seq1 > 0 && seq1 == seq2;
        if(Dp[idx][seq1][seq2] != -1)return Dp[idx][seq1][seq2];
        int ans = 0;
        ans = rec(idx + 1,gcd(seq1,nums[idx]),seq2,nums);
        ans = (ans + rec(idx + 1,seq1,gcd(seq2,nums[idx]),nums)) % mod;
        ans = (ans + rec(idx + 1,seq1,seq2,nums)) % mod;
        return Dp[idx][seq1][seq2] = ans;
    }
    int subsequencePairCount(vector<int>& nums) {
        memset(Dp,-1,sizeof(Dp));
        return rec(0,0,0,nums);
    }
};