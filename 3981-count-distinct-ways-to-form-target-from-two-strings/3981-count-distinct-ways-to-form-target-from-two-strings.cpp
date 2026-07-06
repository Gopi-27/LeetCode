class Solution {
public:
    int Dp[103][103][103][2][2];
    int mod = 1e9 + 7;
    unordered_map<char,vector<int>>mpp1,mpp2;
    int rec(int i,int prev1,int prev2,string& target,int s1,int s2){
        if(i >= target.size()){
            if(s1 && s2)return 1;
            return 0;
        }
        if(Dp[i][prev1][prev2][s1][s2] != -1)return Dp[i][prev1][prev2][s1][s2];
        int ans = 0;
        vector<int>Idx;
        if(mpp1.count(target[i])){
            Idx = mpp1[target[i]];
            for(int j = 0; j < Idx.size(); j++)if(Idx[j] > prev1)
                ans = (ans +  rec(i + 1,Idx[j],prev2,target,1,s2)) % mod;
             
        }
        if(mpp2.count(target[i])){
            Idx = mpp2[target[i]];
            for(int j = 0; j < Idx.size(); j++)if(Idx[j] > prev2)
                ans = (ans +  rec(i + 1,prev1,Idx[j],target,s1,1)) % mod;
        }
        // cout<<i<<" "<<prev1<<" "<<prev2<< " " << s1 << " " << s2 << " " <<ans << endl;
        return Dp[i][prev1][prev2][s1][s2] = ans;
    }
    int interleaveCharacters(string word1, string word2, string target) {
        memset(Dp,-1,sizeof(Dp));
        for(int i = 0; i < word1.size(); i++)mpp1[word1[i]].push_back(i + 1);
        for(int i = 0; i < word2.size(); i++)mpp2[word2[i]].push_back(i + 1);
        return rec(0,0,0,target,0,0);
    }
};