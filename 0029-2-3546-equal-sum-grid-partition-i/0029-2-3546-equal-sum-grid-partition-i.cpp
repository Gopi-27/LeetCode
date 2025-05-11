class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<long long int>Row(m,0);
        vector<long long int>Col(n,0);
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                Row[i] += grid[i][j];
                Col[j] += grid[i][j];
            }
        }
        int left = 0;
        int right = m - 1;
        long long int lsum = 0;
        long long int rsum = 0;
        while(left <= right){
            if(lsum < rsum){
                lsum += Row[left++];
            }else{
                rsum += Row[right--];
            }
        }
        if(lsum == rsum)return true;
        left = 0;
        right = n - 1;
        lsum = 0;
        rsum = 0;
        while(left <= right){
            if(lsum < rsum){
                lsum += Col[left++];
            }else{
                rsum += Col[right--];
            }
        }
        if(lsum == rsum)return true;
        return false;
    }
};