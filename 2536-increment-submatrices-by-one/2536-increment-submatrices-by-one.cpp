class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>>Mat(n,vector<int>(n));
        for(auto q : queries){
            for(int x = q[0]; x <= q[2]; x++){
                Mat[x][q[1]]++;
                if(q[3] + 1 < n)Mat[x][q[3] + 1]--;
            }
        }
        for(int i = 0; i < n; i++){
            int sum = 0;
            for(int j = 0; j < n; j++){
                sum += Mat[i][j];
                Mat[i][j] = sum;
            }
        }
        return Mat;
    }
};