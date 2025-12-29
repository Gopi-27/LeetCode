class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int i = 0;
        int j = 0;
        vector<int>ans;
        int r_bound = n;
        int d_bound = m;
        int l_bound = -1;
        int u_bound = 0;
        while(ans.size() < m * n){
            // right
            while(j < r_bound)ans.push_back(matrix[i][j++]);
            i++;
            j--;
            if(ans.size() == m * n)return ans;
            // down
            while(i < d_bound)ans.push_back(matrix[i++][j]);
            i--;
            j--;
            if(ans.size() == m * n)return ans;
            // left
            while(j > l_bound)ans.push_back(matrix[i][j--]);
            j++;
            i--;
            if(ans.size() == m * n)return ans;
            // up
            while(i > u_bound)ans.push_back(matrix[i--][j]);
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