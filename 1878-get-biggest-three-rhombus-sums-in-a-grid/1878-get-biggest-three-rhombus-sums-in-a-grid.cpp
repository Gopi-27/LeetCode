class Solution {
public:
    
    int GetVal(int i ,int j,int n, int m,vector<vector<int>>& Mat){
        if(i < 0 || j < 0)return 0;
        if(i >= n || j >= m)return 0;
        return Mat[i][j];
    }

    int GetRhomSum(int i,int j,int k,int n, int m,vector<vector<int>>& Forward, vector<vector<int>>& Backward,vector<vector<int>>& grid){
        if(k == 1)return grid[i][j];
        pair<int,int>top = {i,j};
        pair<int,int>left = {i + k - 1,j - k + 1};
        pair<int,int>right = {i + k - 1,j + k - 1};
        pair<int,int>bottom  = {i + k + k - 2,j};
        int sum = 0;
        sum += Forward[left.first][left.second] - GetVal(top.first - 1, top.second + 1,n,m,Forward);
        sum += Forward[bottom.first][bottom.second] - GetVal(right.first - 1, right.second + 1,n,m,Forward);
        sum += Backward[right.first][right.second] - GetVal(top.first - 1,top.second - 1,n,m,Backward);
        sum += Backward[bottom.first][bottom.second] - GetVal(left.first - 1, left.second - 1,n,m,Backward);
        sum -= grid[top.first][top.second] + grid[left.first][left.second];
        sum -= grid[right.first][right.second] + grid[bottom.first][bottom.second];
        return sum;
    }
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>Forward(n,vector<int>(m));
        vector<vector<int>>Backward(n,vector<int>(m));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                Forward[i][j] = grid[i][j] + GetVal(i - 1,j + 1,n,m,Forward);
                Backward[i][j] = grid[i][j] + GetVal(i - 1, j - 1,n,m,Backward);
            }
        }
        set<int,greater<int>>st;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                int left = j + 1;
                int right = m - j;
                int down = (n - i + 1)/2;
                int len = min({left,right,down});
                cout << len << " ";
                for(int k = 1; k <= len; k++){
                    st.insert(GetRhomSum(i,j,k,n,m,Forward,Backward,grid));
                }
            }
        }
        vector<int>A;
        int cnt = 0;
        for(auto b : st){
            A.push_back(b);
            cnt++;
            if(cnt == 3)break;
        }
        return A;
    }
};