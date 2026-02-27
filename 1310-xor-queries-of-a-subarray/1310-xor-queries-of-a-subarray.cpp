class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int>Pref(n + 1);
        for(int i = 1; i <= n; i++){
            Pref[i] = Pref[i - 1] ^ arr[i - 1];
        }
        vector<int>ans;
        for(auto q : queries){
            ans.push_back(Pref[q[1] + 1] ^ Pref[q[0]]);
        }
        return ans;
    }
};