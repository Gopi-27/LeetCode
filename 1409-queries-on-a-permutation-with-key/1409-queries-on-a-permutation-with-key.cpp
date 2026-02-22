class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
        int n = queries.size();
        vector<int>A(m + 1);
        for(int i = 1; i <= m; i++)A[i] = i;
        vector<int>res(n);
        for(int i = 0; i < n; i++){
            res[i] = A[queries[i]] - 1;
            int key = A[queries[i]];
            for(int j = 1; j <= m; j++){
                if(j == queries[i])A[j] = 1;
                else if(A[j] < key)A[j]++;
            }
        }
        return res;
    }
};