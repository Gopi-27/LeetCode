class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int i = 0;
        int j = 0;
        vector<vector<int>>ans(n,vector<int>(n));
        int r_bound = n;
        int d_bound = n;
        int l_bound = -1;
        int u_bound = 0;
        int val = 0;
        while(val < n * n){
            // right
            while(j < r_bound)ans[i][j++] = ++val;
            i++;
            j--;
            if(val == n * n)return ans;
            // down
            while(i < d_bound)ans[i++][j] = ++val;
            i--;
            j--;
            if(val == n * n)return ans;
            // left
            while(j > l_bound)ans[i][j--] = ++val;
            j++;
            i--;
            if(val == n * n)return ans;
            // up
            while(i > u_bound)ans[i--][j] = ++val;
            i++;
            j++;

            r_bound--;
            d_bound--;
            l_bound++;
            u_bound++;
        } 
        return ans;
    }
};