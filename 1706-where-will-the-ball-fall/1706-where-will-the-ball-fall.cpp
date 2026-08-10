class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int>Ans(m);
        for(int k = 0; k < m; k++){
            int i = 0;
            int j = k;
            bool flag = 0;
            while(i < n){
                if(grid[i][j] == 1){
                    if(j + 1 == m || grid[i][j + 1] == -1){
                        flag = 1;
                        break;
                    }else{
                        i++;
                        j++;
                    }
                }else{// -1
                    if(j - 1 < 0 || grid[i][j - 1] == 1){
                        flag = 1;
                        break;
                    }else{
                        i++;
                        j--;
                    }
                }
            }
            
            if(flag)Ans[k] = -1;
            else Ans[k] = j;
        }
        return Ans;

    }
};