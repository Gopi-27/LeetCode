class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                bool flag = 1;
                for(int k = 0; k < n; k++){
                    if(grid[i][k] != grid[k][j]){
                        flag = 0;
                        break;
                    }
                }
                if(flag)ans++;
            }
        }
        return ans;
    }
};

// [3,1,2,2]
// [1,4,4,4]
// [2,4,2,2]
// [2,4,2,2]