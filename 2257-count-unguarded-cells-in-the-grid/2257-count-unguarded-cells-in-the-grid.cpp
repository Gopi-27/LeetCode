class Solution {
public:
    void DisPatch(vector<vector<char>>& Mat,int x,int y){
        Mat[x][y] = 'G';
        int m = Mat.size();
        int n = Mat[0].size();
        int i = x - 1,j = y + 1;
        
        // right
        while(j < n && (Mat[x][j] == '.' || Mat[x][j] == 'R')){
            Mat[x][j] = 'C';
            j++;
        }
        // left
        j = y - 1;
        while(j >= 0 && (Mat[x][j] == '.' || Mat[x][j] == 'R')){
            Mat[x][j] = 'C';
            j--;
        }
        // up
        while(i >= 0 && (Mat[i][y] == '.' || Mat[i][y] == 'C')){
            Mat[i][y] = 'R';
            i--;
        }
        // bottom
        i = x + 1;
        while(i < m && (Mat[i][y] == '.' || Mat[i][y] == 'C')){
            Mat[i][y] = 'R';
            i++;
        }
        return;
    }
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
       // brute Force
       vector<vector<char>>Mat(m,vector<char>(n,'.'));
       for(int i = 0; i < walls.size(); i++)Mat[walls[i][0]][walls[i][1]] = 'W';
       for(int i = 0; i < guards.size(); i++)DisPatch(Mat,guards[i][0],guards[i][1]);
       int ans = 0;
       for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                if(Mat[i][j] == '.')
                    ans++;                        
       return ans;
    }
};