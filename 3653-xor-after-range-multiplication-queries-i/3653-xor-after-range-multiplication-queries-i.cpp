#define MOD 1000000007 

class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = queries.size();

        for(int i = 0; i < n; i++){
            int idx = queries[i][0];
            int r = queries[i][1];
            while(idx <= r){
                long long val = (1LL * nums[idx] * queries[i][3]) % MOD;
                nums[idx] = val;
                idx += queries[i][2];
            }            
        }
        int ans = 0;
        for(int i= 0; i < nums.size(); i++)ans ^= nums[i];
        return ans;
        
    }
};