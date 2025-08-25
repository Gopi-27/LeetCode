class Solution {
public:
    void AddElements(vector<vector<int>>& mat,vector<int>& Ans,pair<int,int>start,pair<int,int>end,pair<int,int>val){
        cout << start.first << " "<< start.second << end.first << " " << end.second << endl;
        while(start.first != end.first){
            Ans.push_back(mat[start.first][start.second]);
            start.first += val.first;
            start.second += val.second;
        }
        Ans.push_back(mat[end.first][end.second]);
        return;
    }
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int>Ans;

        pair<int,int>up = {0,0};
        pair<int,int>down = {0,0};

        int rows = mat.size();
        int cols = mat[0].size();
        bool flag = true;

        pair<int,int>upval = {0,1};
        pair<int,int>downval = {1,0};

        while(up.first != rows){

            if(flag)AddElements(mat,Ans,down,up,{-1,1});
            else AddElements(mat,Ans,up,down,{1,-1});

            if(up.first == 0 && up.second == cols - 1){
                upval.first = 1;
                upval.second = 0;
            }

            if(down.first == rows - 1 && down.second == 0){
                downval.first = 0;
                downval.second = 1;
            }
                
            up.first += upval.first;
            up.second += upval.second;

            down.first += downval.first;
            down.second += downval.second;

            flag = !flag;
        }
        return Ans;


    }
};














