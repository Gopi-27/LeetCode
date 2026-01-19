class Solution {
public:
    bool Valid(int r,int c,int k,int threshold,vector<vector<int>>& mat){
         int sum = 0;
         for(int i = r; i < r + k; i++){
            sum += mat[i][c + k - 1];
            if(c > 0)sum -= mat[i][c - 1];
         }
         return sum <= threshold;
    }
    bool Check(int k,vector<vector<int>>& mat,int threshold){
        if(k == 0)return true;
        int n = mat.size();
        int m = mat[0].size();
        for(int i = k - 1; i < n; i++){
            for(int j = k - 1; j < m; j++){
                if(Valid(i - k + 1,j - k + 1,k,threshold,mat))return true;
            }
        }
        return false;
    }
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int n = mat.size();
        int m = mat[0].size();
        for(int i = 0; i < n; i++){
            for(int j = 1; j < m; j++){
                mat[i][j] += mat[i][j - 1];
            }
        }
        int k = min(n,m);
        int low = 0;
        int high = k;
        while(low <= high){
            int mid = (low + high) >> 1;
            if(Check(mid,mat,threshold))low = mid + 1;
            else high = mid - 1;
        }
        return high;
    }
};