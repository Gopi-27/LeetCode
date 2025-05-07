class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int>Ans(n);
        vector<int>frr(n + 1, 0);
        int cnt = 0;
        for(int i = 0; i < n; i++){
            frr[A[i]]++;
            if(frr[A[i]] == 2)cnt++;
            frr[B[i]]++;
            if(frr[B[i]] == 2)cnt++;
            Ans[i] = cnt;
        }
        return Ans;
    }
};
