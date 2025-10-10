class Solution {
public:
    int rec(int idx,vector<int>&Dp,vector<int>& E,int k){
        
        if(idx >= E.size())return 0;
        
        int ans = E[idx] +  rec(idx + k,Dp,E,k);
        
        return Dp[idx] = ans;
    }
    int maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size();
        int ans = INT_MIN;
        vector<int>Dp(n);
        for(int i = 0; i < k; i++){
            ans = max(ans,rec(i,Dp,energy,k));

        }
        for(int i=k;i<n;i++){
            ans=max(ans,Dp[i]);
        }
        return ans;
   }                                        
};