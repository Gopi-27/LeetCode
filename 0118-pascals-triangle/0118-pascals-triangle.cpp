class Solution {
public:
    int GetValue(vector<vector<int>>& A,int col,int row){
        if(col == 0)return A[row][0];
        if(row < col)return A[row][col - 1];
        return A[row][col - 1] + A[row][col];
    }
    vector<vector<int>> generate(int n) {
        vector<vector<int>>Ans;
        Ans.push_back({1});
        if(n == 1)return Ans;
        for(int i = 1; i < n; i++){
             vector<int>temp;
             for(int j = 0; j < i + 1; j++){
                    temp.push_back(GetValue(Ans,j,i - 1));
             }
             Ans.push_back(temp);            
        }
        return Ans;
    }
};