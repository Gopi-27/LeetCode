#define ll long long
class Solution {
public:
    int mod = 1e9 + 7;
    int countPaths(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>>InDeg(n,vector<int>(m));
        vector<vector<ll>>Len(n,vector<ll>(m,1));
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(j - 1 >= 0 && grid[i][j - 1] < grid[i][j])InDeg[i][j - 1]++;
                if(j + 1 < m && grid[i][j + 1] < grid[i][j])InDeg[i][j + 1]++;
                if(i - 1 >= 0 && grid[i - 1][j] < grid[i][j])InDeg[i - 1][j]++;
                if(i + 1 < n && grid[i + 1][j] < grid[i][j])InDeg[i + 1][j]++;              
            }
        }

        // i j len 
        queue<vector<ll>>Q;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(!InDeg[i][j])Q.push({i,j,Len[i][j]});
        
        ll ans = 0;
        while(!Q.empty()){
            ll i = Q.front()[0];
            ll j = Q.front()[1];
            ll l = Q.front()[2];Q.pop();
            ans = (ans + l) % mod;
            if(j - 1 >= 0 && grid[i][j - 1] < grid[i][j]){
                InDeg[i][j - 1]--;
                Len[i][j - 1] = (Len[i][j - 1] + l) % mod;
                if(!InDeg[i][j - 1])Q.push({i,j - 1,Len[i][j - 1]});
            }
            if(j + 1 < m && grid[i][j + 1] < grid[i][j]){
                InDeg[i][j + 1]--;
                Len[i][j + 1] = (Len[i][j + 1] + l) % mod;
                if(!InDeg[i][j + 1])Q.push({i,j + 1,Len[i][j + 1]});
            }

            if(i - 1 >= 0 && grid[i - 1][j] < grid[i][j]){
                InDeg[i - 1][j]--;
                Len[i - 1][j] = ( Len[i - 1][j] + l) % mod;
                if(!InDeg[i - 1][j])Q.push({i - 1,j,Len[i - 1][j]});
            }

            if(i + 1 < n && grid[i + 1][j] < grid[i][j]){
                InDeg[i + 1][j]--;
                Len[i + 1][j] = (Len[i + 1][j] + l) % mod;
                if(!InDeg[i + 1][j])Q.push({i + 1,j,Len[i + 1][j]});
            }                
            
        }
        return ans;
    }
};
//   6
//   5
// 1 2 3 4 5 6 7
//   3 