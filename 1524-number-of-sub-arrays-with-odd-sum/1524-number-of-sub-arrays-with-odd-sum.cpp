class Solution {
public:
    int mod = 1e9 + 7;
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();
        int ans = 0;
        int pref = 0;
        int ocnt = 0;
        int ecnt = 1;
        for(int i = 0; i < n; i++){
            pref = (pref + arr[i]) % 2;
            if(pref % 2 == 0){
                ans = (ans + ocnt) % mod;
                ecnt++;
            }else{
                ans = (ans + ecnt) % mod;
                ocnt++;
            }
        }
        return ans;
    }
};