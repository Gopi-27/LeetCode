#define MOD 1000000007
class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        int cnt = 0;
        vector<int>powers;
        while(n > 0){
            if(n & 1)powers.push_back(pow(2,cnt));
            cnt++;
            n >>= 1;
        }
        int len = queries.size();
        vector<int>Ans(len,1);
        for(int i = 0; i < len; i++){
            long long val = 1;
            for(int j = queries[i][0]; j <= queries[i][1]; j++){
                val = (val * powers[j]) % MOD;
            }
            Ans[i] = val;
        }
        return Ans;

    }
};