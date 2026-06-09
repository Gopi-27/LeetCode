class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int>Row(n);
        vector<int>Col(m);
        int tot = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j]){
                    Row[i]++;
                    Col[j]++;
                }
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j]){
                    if(Row[i] > 1 || Col[j] > 1)tot++;
                }
            }
        }
        return tot;
    }
};