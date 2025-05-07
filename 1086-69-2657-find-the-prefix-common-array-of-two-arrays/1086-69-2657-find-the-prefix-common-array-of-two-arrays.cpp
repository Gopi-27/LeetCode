class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int>Ans(n);
        vector<int>frr(n + 1, 0);
        for(int i = 0; i < n; i++){
            frr[A[i]]++;
            frr[B[i]]++;
            int cnt = 0;
            for(int j = 0; j < n + 1; j++){
                cnt += frr[j]/2;
            }
            Ans[i] = cnt;
        }
        return Ans;
    }
};