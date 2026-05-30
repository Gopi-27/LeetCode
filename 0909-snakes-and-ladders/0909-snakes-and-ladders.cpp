class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        vector<int>B;
        B.push_back(-1);
        int r = 0;
        for(int i = n - 1; i >= 0; i--){
            if(r % 2 == 0)for(int j = 0; j < n; j++)B.push_back(board[i][j]);
            else for(int j = n - 1; j >= 0; j--)B.push_back(board[i][j]);
            r++;
        }
        vector<int>Vis(n * n + 1,1e8);
        queue<pair<int,int>>Q;
        Q.push({1,0});
        Vis[1] = 0;
        while(!Q.empty()){
            int u = Q.front().first;
            int mvs = Q.front().second;Q.pop();
            for(int v = u + 1; v <= u + 6 && v <= n * n; v++){
                int des = v;
                if(B[v] != -1)des = B[v];
                // cout << des << " -> ";
                if(Vis[des] > mvs + 1){
                    Vis[des] = mvs + 1;
                    Q.push({des,Vis[des]});
                }
            }
        }
        return (Vis[n * n] == 1e8) ? -1 : Vis[n * n];
    }
};