class Solution {
public:
    int mod = 1e9 + 7;
    int numberOfWays(string corridor) {
        long long ans = 1;
        vector<int>Idx;
        for(int i = 0; i < corridor.size(); i++)
            if(corridor[i] == 'S')Idx.push_back(i);        
        int n = Idx.size();
        if(n % 2 == 1)return 0;
        if(n <= 1)return 0;
        for(int i = 2; i < n; i += 2){
            ans *= Idx[i] - Idx[i - 1];
            ans %= mod;
        } 
        return ans;
    }
};