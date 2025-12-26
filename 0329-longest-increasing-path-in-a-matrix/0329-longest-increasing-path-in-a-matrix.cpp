class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>>Dp(m,vector<int>(n));
        vector<vector<int>>InDeg(m,vector<int>(n));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(j + 1 < n && matrix[i][j] > matrix[i][j + 1])InDeg[i][j]++;
                if(j - 1 >= 0 && matrix[i][j] > matrix[i][j - 1])InDeg[i][j]++;
                if(i + 1 < m && matrix[i][j] > matrix[i + 1][j])InDeg[i][j]++;
                if(i - 1 >= 0 && matrix[i][j] > matrix[i - 1][j])InDeg[i][j]++;
            }
        }

        queue<pair<int,int>>Q;
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                if(!InDeg[i][j])Q.push({i,j});
        int maxi = 0;
        while(!Q.empty()){
            int i = Q.front().first;
            int j = Q.front().second;Q.pop();
            Dp[i][j] = 1;
            if(j + 1 < n && matrix[i][j] > matrix[i][j + 1]){
                Dp[i][j] = max(Dp[i][j], 1 + Dp[i][j + 1]);
            }
            if(j - 1 >= 0 && matrix[i][j] > matrix[i][j - 1]){
                Dp[i][j] = max(Dp[i][j], 1 + Dp[i][j - 1]);
            }
            if(i + 1 < m && matrix[i][j] > matrix[i + 1][j]){
                Dp[i][j] = max(Dp[i][j], 1 + Dp[i + 1][j]);
            }
            if(i - 1 >= 0 && matrix[i][j] > matrix[i - 1][j]){
                Dp[i][j] = max(Dp[i][j], 1 + Dp[i - 1][j]);
            }

            if(j + 1 < n && matrix[i][j] < matrix[i][j + 1]){
                if(!--InDeg[i][j + 1])Q.push({i,j + 1});
            }
            if(j - 1 >= 0 && matrix[i][j] < matrix[i][j - 1]){
                if(!--InDeg[i][j - 1])Q.push({i,j - 1});
            }
            if(i + 1 < m && matrix[i][j] < matrix[i + 1][j]){
                if(!--InDeg[i + 1][j])Q.push({i + 1, j});
            }
            if(i - 1 >= 0 && matrix[i][j] < matrix[i - 1][j]){
                if(!--InDeg[i - 1][j])Q.push({i - 1, j});
            }

            maxi = max(maxi,Dp[i][j]);
        }
        return maxi;
    }
};