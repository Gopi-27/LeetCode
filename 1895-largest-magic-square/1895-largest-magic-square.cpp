class Solution {
public:
    bool Valid(int i,int j,int k,vector<vector<int>>& grid){
        // k rows
        // k cols
        // 2 dia
        int l = i - k + 1;
        int r = j - k + 1;
        int key = 0;
        for(int t = 0; t < k; t++)key += grid[l + t][r + t];
        cout << key << endl;
        for(int row = l; row < l + k; row++){
            int rsum = 0;
            for(int col = r; col < r + k; col++){
                rsum += grid[row][col];
            }
            cout << rsum << endl;
            if(rsum != key)return false;
        }
        for(int col = r; col < r + k; col++){
            int rsum = 0;
            for(int row = l; row < l + k; row++){
                rsum += grid[row][col];
            }
             cout << rsum << endl;
            if(rsum != key)return false;
        }

        // l =  i - k + 1;
        int val = 0;
        for(int t = 0; t < k; t++)val += grid[l + t][j - t];
        cout << val << endl;
        if(val != key)return false;
        return true;     
    }
    bool Check(int k,vector<vector<int>>& grid){
        int n = grid.size();
        int m = grid[0].size();

        for(int i = k - 1; i < n; i++){
            for(int j = k - 1; j < m; j++){
                if(Valid(i,j,k,grid))return true;
            }
        }
        return false;

    }
    int largestMagicSquare(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int k = min(m,n);
        while(!Check(k,grid))k--;
        return k;
    }
};